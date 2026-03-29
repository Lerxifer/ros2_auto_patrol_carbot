from setuptools import find_packages, setup

package_name = 'carbot_application'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='luxifer',
    maintainer_email='luoxi20030116@163.com',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'nav_2_pos = carbot_application.nav_2_pos:main',
            'get_carbot_pose = carbot_application.get_carbot_pose:main',
            'init_robot_pose = carbot_application.init_robot_pose:main'
        ],
    },
)
