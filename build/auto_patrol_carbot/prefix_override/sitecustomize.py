import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/luxifer/LearningRoom/navigation_ws/src/install/auto_patrol_carbot'
