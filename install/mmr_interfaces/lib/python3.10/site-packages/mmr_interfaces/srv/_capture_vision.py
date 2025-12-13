# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mmr_interfaces:srv/CaptureVision.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'initial_pose'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CaptureVision_Request(type):
    """Metaclass of message 'CaptureVision_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mmr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mmr_interfaces.srv.CaptureVision_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__capture_vision__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__capture_vision__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__capture_vision__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__capture_vision__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__capture_vision__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CaptureVision_Request(metaclass=Metaclass_CaptureVision_Request):
    """Message class 'CaptureVision_Request'."""

    __slots__ = [
        '_mode',
        '_initial_pose',
    ]

    _fields_and_field_types = {
        'mode': 'int32',
        'initial_pose': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mode = kwargs.get('mode', int())
        self.initial_pose = array.array('d', kwargs.get('initial_pose', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.mode != other.mode:
            return False
        if self.initial_pose != other.initial_pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mode' field must be an integer in [-2147483648, 2147483647]"
        self._mode = value

    @builtins.property
    def initial_pose(self):
        """Message field 'initial_pose'."""
        return self._initial_pose

    @initial_pose.setter
    def initial_pose(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'initial_pose' array.array() must have the type code of 'd'"
            self._initial_pose = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'initial_pose' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._initial_pose = array.array('d', value)


# Import statements for member types

# Member 'poses_x'
# Member 'poses_y'
# Member 'poses_z'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_CaptureVision_Response(type):
    """Metaclass of message 'CaptureVision_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mmr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mmr_interfaces.srv.CaptureVision_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__capture_vision__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__capture_vision__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__capture_vision__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__capture_vision__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__capture_vision__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CaptureVision_Response(metaclass=Metaclass_CaptureVision_Response):
    """Message class 'CaptureVision_Response'."""

    __slots__ = [
        '_success',
        '_num_objects',
        '_poses_x',
        '_poses_y',
        '_poses_z',
        '_tags',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'num_objects': 'int32',
        'poses_x': 'sequence<double>',
        'poses_y': 'sequence<double>',
        'poses_z': 'sequence<double>',
        'tags': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.num_objects = kwargs.get('num_objects', int())
        self.poses_x = array.array('d', kwargs.get('poses_x', []))
        self.poses_y = array.array('d', kwargs.get('poses_y', []))
        self.poses_z = array.array('d', kwargs.get('poses_z', []))
        self.tags = kwargs.get('tags', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.num_objects != other.num_objects:
            return False
        if self.poses_x != other.poses_x:
            return False
        if self.poses_y != other.poses_y:
            return False
        if self.poses_z != other.poses_z:
            return False
        if self.tags != other.tags:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def num_objects(self):
        """Message field 'num_objects'."""
        return self._num_objects

    @num_objects.setter
    def num_objects(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_objects' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_objects' field must be an integer in [-2147483648, 2147483647]"
        self._num_objects = value

    @builtins.property
    def poses_x(self):
        """Message field 'poses_x'."""
        return self._poses_x

    @poses_x.setter
    def poses_x(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'poses_x' array.array() must have the type code of 'd'"
            self._poses_x = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'poses_x' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._poses_x = array.array('d', value)

    @builtins.property
    def poses_y(self):
        """Message field 'poses_y'."""
        return self._poses_y

    @poses_y.setter
    def poses_y(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'poses_y' array.array() must have the type code of 'd'"
            self._poses_y = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'poses_y' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._poses_y = array.array('d', value)

    @builtins.property
    def poses_z(self):
        """Message field 'poses_z'."""
        return self._poses_z

    @poses_z.setter
    def poses_z(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'poses_z' array.array() must have the type code of 'd'"
            self._poses_z = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'poses_z' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._poses_z = array.array('d', value)

    @builtins.property
    def tags(self):
        """Message field 'tags'."""
        return self._tags

    @tags.setter
    def tags(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'tags' field must be a set or sequence and each value of type 'str'"
        self._tags = value


class Metaclass_CaptureVision(type):
    """Metaclass of service 'CaptureVision'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mmr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mmr_interfaces.srv.CaptureVision')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__capture_vision

            from mmr_interfaces.srv import _capture_vision
            if _capture_vision.Metaclass_CaptureVision_Request._TYPE_SUPPORT is None:
                _capture_vision.Metaclass_CaptureVision_Request.__import_type_support__()
            if _capture_vision.Metaclass_CaptureVision_Response._TYPE_SUPPORT is None:
                _capture_vision.Metaclass_CaptureVision_Response.__import_type_support__()


class CaptureVision(metaclass=Metaclass_CaptureVision):
    from mmr_interfaces.srv._capture_vision import CaptureVision_Request as Request
    from mmr_interfaces.srv._capture_vision import CaptureVision_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
