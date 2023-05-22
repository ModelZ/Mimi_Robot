from setuptools import find_packages
from setuptools import setup

setup(
    name='mimi_head',
    version='0.0.0',
    packages=find_packages(
        include=('mimi_head', 'mimi_head.*')),
)
