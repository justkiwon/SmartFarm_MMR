import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/pandora/dev/strawberry/ros2_pro/install/kinetic'
