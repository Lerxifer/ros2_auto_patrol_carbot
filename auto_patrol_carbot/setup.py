from setuptools import find_packages, setup
import os

package_name = 'auto_patrol_carbot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), 
            [os.path.join('launch', 'carbot_patrol.launch.py')]),
        (os.path.join('share', package_name, 'config'), 
            [os.path.join('config', 'patrol_params_config.yaml')]),
    ],
    install_requires=['setuptools', 'espeakng'],
    zip_safe=True,
    maintainer='luxifer',
    maintainer_email='luoxi20030116@163.com',
    description='自动巡逻机器人节点',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'auto_patrol_node = auto_patrol_carbot.auto_patrol_node:main',
            'speak_node = auto_patrol_carbot.speak:main',
        ],
    },
)
