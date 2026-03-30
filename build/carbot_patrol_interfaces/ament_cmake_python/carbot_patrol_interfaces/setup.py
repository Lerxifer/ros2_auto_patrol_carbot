from setuptools import find_packages
from setuptools import setup

setup(
    name='carbot_patrol_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('carbot_patrol_interfaces', 'carbot_patrol_interfaces.*')),
)
