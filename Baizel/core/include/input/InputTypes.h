#ifndef BAIZEL_INPUTTYPES_H
#define BAIZEL_INPUTTYPES_H

#include <list>

#include <input/InputDevice.h>

namespace baizel
{
	const unsigned int gkMaximumEvents = 15;

	enum eInputDeviceType
	{
		eInputDeviceType_Keyboard,
		eInputDeviceType_Mouse,
		eInputDeviceType_Gamepad,

		eInputDeviceType_Count
	};

    using tInputDevicesArray = iInputDevice* [eInputDeviceType_Count];

    enum eKey
    {
        eKey_BACKSPACE,
        eKey_TAB,
        eKey_ENTER,
        eKey_RETURN,
        eKey_ESCAPE,
        eKey_SPACE,
        eKey_UP,
        eKey_DOWN,
        eKey_LEFT,
        eKey_RIGHT,
        eKey_SHIFT,
        eKey_CTRL,
        eKey_ALT,
        eKey_F1,
        eKey_F2,
        eKey_F3,
        eKey_F4,
        eKey_F5,
        eKey_F6,
        eKey_F7,
        eKey_F8,
        eKey_F9,
        eKey_F10,
        eKey_F11,
        eKey_F12,

        eKey_A,
        eKey_B,
        eKey_C,
        eKey_D,
        eKey_E,
        eKey_F,
        eKey_G,
        eKey_H,
        eKey_I,
        eKey_J,
        eKey_K,
        eKey_L,
        eKey_M,
        eKey_N,
        eKey_O,
        eKey_P,
        eKey_Q,
        eKey_R,
        eKey_S,
        eKey_T,
        eKey_U,
        eKey_V,
        eKey_W,
        eKey_X,
        eKey_Y,
        eKey_Z,

        eKey_0,
        eKey_1,
        eKey_2,
        eKey_3,
        eKey_4,
        eKey_5,
        eKey_6,
        eKey_7,
        eKey_8,
        eKey_9,

        eKey_NONE,

        eKey_Count
    };

	enum eMouseButton
	{
		eMouseButton_Left,
		eMouseButton_Middle,
		eMouseButton_Right,

        eMouseButton_WheelUp,
        eMouseButton_WheelDown,

		eMouseButton_None,

		eMouseButton_Count
	};
}

#endif // BAIZEL_INPUTTYPES_H