#!/usr/bin/env python3
import os
import rclpy
from rclpy.node import Node
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from geometry_msgs.msg import PoseStamped
from tf_transformations import euler_from_quaternion, quaternion_from_euler
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from carbot_patrol_interfaces.srv import Speech

class PatrolNode(BasicNavigator):
    def __init__(self):
        super().__init__(node_name='patrol_node')
        # 初始化参数
        self.declare_parameter('initial_point', [0.0, 0.0, 0.0])
        self.declare_parameter('target_points', [0.0, 0.0, 0.0, 1.0, 1.0, 1.57])
        self.initial_point_ = self.get_parameter('initial_point').value
        self.target_points_ = self.get_parameter('target_points').value
        
        # 语音服务客户端
        self.speech_client = self.create_client(Speech, 'speech_text')
        while not self.speech_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('语音服务不可用，正在等待...')
        
        # 订阅与保存图像相关定义
        self.bridge = CvBridge()
        self.image_save_path = '/home/luxifer/navigation_ws/images/'
        if not os.path.exists(self.image_save_path):
            os.makedirs(self.image_save_path)
        self.image_count = 0
        self.subscription_image = self.create_subscription(
            Image, '/camera/image_raw', self.image_callback, 10)

    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            self.current_image = cv_image
        except Exception as e:
            self.get_logger().error('图像转换失败: %s' % str(e))

    def speach_text(self, text):
        request = Speech.Request()
        request.text = text
        future = self.speech_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info('语音合成成功')
        else:
            self.get_logger().error('语音合成失败')

    def get_pose_by_xyyaw(self, x, y, yaw):
        """
        通过 x,y,yaw 合成 PoseStamped
        """
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.pose.position.x = x
        pose.pose.position.y = y
        rotation_quat = quaternion_from_euler(0, 0, yaw)
        pose.pose.orientation.x = rotation_quat[0]
        pose.pose.orientation.y = rotation_quat[1]
        pose.pose.orientation.z = rotation_quat[2]
        pose.pose.orientation.w = rotation_quat[3]
        return pose

    def init_robot_pose(self):
        """
        初始化机器人位置
        """
        initial_pose = self.get_pose_by_xyyaw(
            self.initial_point_[0], self.initial_point_[1], self.initial_point_[2])
        self.setInitialPose(initial_pose)
        self.speach_text('正在初始化位置')
        self.waitUntilNav2Active()
        self.speach_text('位置初始化完成')

    def get_target_points(self):
        """
        获取目标点列表
        """
        points = []
        self.target_points_ = self.get_parameter('target_points').value
        for index in range(int(len(self.target_points_)/3)):
            x = self.target_points_[index*3]
            y = self.target_points_[index*3+1]
            yaw = self.target_points_[index*3+2]
            points.append([x, y, yaw])
            self.get_logger().info(f'获取到目标点: {index}->({x},{y},{yaw})')
        return points

    def record_image(self):
        """
        记录图像
        """
        try:
            if hasattr(self, 'current_image'):
                filename = f'point_{self.image_count}.jpg'
                filepath = os.path.join(self.image_save_path, filename)
                cv2.imwrite(filepath, self.current_image)
                self.get_logger().info(f'图像已保存: {filepath}')
                self.image_count += 1
            else:
                self.get_logger().warn('没有收到图像数据')
        except Exception as e:
            self.get_logger().error('保存图像失败: %s' % str(e))

    def nav_to_pose(self, pose):
        """
        导航到指定位置
        """
        self.goToPose(pose)
        while not self.isTaskComplete():
            feedback = self.getFeedback()
            if feedback:
                self.get_logger().info('距离目标点还剩: %.2f 米' % feedback.distance_remaining)
        result = self.getResult()
        if result == TaskResult.SUCCEEDED:
            self.get_logger().info('导航结果：成功')
        elif result == TaskResult.CANCELED:
            self.get_logger().warn('导航结果：被取消')
        elif result == TaskResult.FAILED:
            self.get_logger().error('导航结果：失败')
        else:
            self.get_logger().error('导航结果：返回状态无效')

    def get_current_pose(self):
        """
        通过TF获取当前位姿
        """
        while rclpy.ok():
            try:
                tf = self.buffer_.lookup_transform(
                    'map', 'base_footprint', rclpy.time.Time(seconds=0), rclpy.time.Duration(seconds=1))
                transform = tf.transform
                rotation_euler = euler_from_quaternion([
                    transform.rotation.x,
                    transform.rotation.y,
                    transform.rotation.z,
                    transform.rotation.w
                ])
                return transform.translation, rotation_euler
            except Exception as e:
                self.get_logger().warn('获取位姿失败: %s' % str(e))
                rclpy.sleep(0.5)


def main():
    rclpy.init()
    patrol = PatrolNode()
    patrol.get_logger().info('正在初始化位置')
    patrol.init_robot_pose()
    patrol.get_logger().info('位置初始化完成')

    while rclpy.ok():
        for point in patrol.get_target_points():
            x, y, yaw = point[0], point[1], point[2]
            # 导航到目标点
            target_pose = patrol.get_pose_by_xyyaw(x, y, yaw)
            patrol.get_logger().info(f'准备前往目标点{x},{y}')
            patrol.speach_text(f'准备前往目标点{x},{y}')
            patrol.nav_to_pose(target_pose)
            patrol.get_logger().info(f"已到达目标点{x},{y},准备记录图像")
            patrol.speach_text(f"已到达目标点{x},{y},准备记录图像")
            patrol.record_image()
            patrol.get_logger().info(f"图像记录完成")
            patrol.speach_text("图像记录完成")

    rclpy.shutdown()
