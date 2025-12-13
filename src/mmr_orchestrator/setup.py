from setuptools import setup

package_name = 'mmr_orchestrator'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', [f'resource/{package_name}']),
        (f'share/{package_name}', ['package.xml']),
        (f'share/{package_name}/launch', ['launch/mmr_system.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='you',
    maintainer_email='you@example.com',
    description='MMR main orchestrator node',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'mmr_orchestrator_node = mmr_orchestrator.mmr_orchestrator_node:main',
        ],
    },
)
