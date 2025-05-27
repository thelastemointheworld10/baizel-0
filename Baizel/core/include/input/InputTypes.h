#ifndef BAIZEL_INPUTTYPES_H
#define BAIZEL_INPUTTYPES_H

#include <vector>

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
        eKey_BackSpace,
        eKey_Tab,
        eKey_Clear,
        eKey_Return,
        eKey_Pause,
        eKey_Escape,
        eKey_Space,
        eKey_Exclaim,
        eKey_QuoteDouble,
        eKey_Hash,
        eKey_Dollar,
        eKey_Ampersand,
        eKey_Quote,
        eKey_LeftParen,
        eKey_RightParen,
        eKey_Asterisk,
        eKey_Plus,
        eKey_Comma,
        eKey_Minus,
        eKey_Period,
        eKey_Slash,
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
        eKey_Colon,
        eKey_SemiColon,
        eKey_Less,
        eKey_Equals,
        eKey_Greater,
        eKey_Question,
        eKey_At,
        eKey_LeftBracket,
        eKey_BackSlash,
        eKey_RightBracket,
        eKey_Caret,
        eKey_Underscore,
        eKey_BackQuote,
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
        eKey_Delete,
        eKey_KP_0,
        eKey_KP_1,
        eKey_KP_2,
        eKey_KP_3,
        eKey_KP_4,
        eKey_KP_5,
        eKey_KP_6,
        eKey_KP_7,
        eKey_KP_8,
        eKey_KP_9,
        eKey_KP_Period,
        eKey_KP_Divide,
        eKey_KP_Multiply,
        eKey_KP_Minus,
        eKey_KP_Plus,
        eKey_KP_Enter,
        eKey_KP_Equals,
        eKey_Up,
        eKey_Down,
        eKey_Right,
        eKey_Left,
        eKey_Insert,
        eKey_Home,
        eKey_End,
        eKey_PageUp,
        eKey_PageDown,
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
        eKey_F13,
        eKey_F14,
        eKey_F15,
        eKey_NumLock,
        eKey_CapsLock,
        eKey_ScrollLock,
        eKey_RightShift,
        eKey_LeftShift,
        eKey_RightCtrl,
        eKey_LeftCtrl,
        eKey_RightAlt,
        eKey_LeftAlt,
        eKey_LeftSuper,
        eKey_RightSuper,
        eKey_Mode,
        eKey_Help,
        eKey_Print,
        eKey_SysReq,
        eKey_Menu,
        eKey_Power,

        eKey_Count,

        eKey_None,
    };

	enum eMouseButton
	{
		eMouseButton_Left,
		eMouseButton_Middle,
		eMouseButton_Right,

        eMouseButton_WheelUp,
        eMouseButton_WheelDown,

		eMouseButton_Count,

		eMouseButton_None
	};

    using tMouseButtonVector = std::vector<eMouseButton>;
    using tKeyboardKeyVector = std::vector<eKey>;
}

#endif // BAIZEL_INPUTTYPES_H