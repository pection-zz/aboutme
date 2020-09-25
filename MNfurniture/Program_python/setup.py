from setuptools import setup
setup(
    name='MN furniture Setup File',
    version='1.0',
    packages=find_packages(),
    entry_points={
        'console_scripts':[
        'my_start=my_pacage.start:main',
        ]
    }
)
