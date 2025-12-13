from setuptools import setup

package_name = 'amr_controller'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', [f'resource/{package_name}']),
        (f'share/{package_name}', ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='you',
    maintainer_email='you@example.com',
    description='AMR move distance service server',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'amr_move_node = amr_controller.move_node:main',
        ],
    },
)
