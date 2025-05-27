#ifndef BAIZEL_KEYBOARD_H
#define BAIZEL_KEYBOARD_H

#include <input/InputDevice.h>
#include <input/InputTypes.h>

namespace baizel
{
	class iKeyboard : public iInputDevice
	{
	public:
		iKeyboard();

		virtual bool GetAnyKeyPressed() const = 0;
		virtual bool GetKeyPressed(eKey aKey) const = 0;
		eKey GetLastKey() const;

	protected:
		tKeyboardKeyVector mvPressedKeys;
	};
}

#endif // BAIZEL_KEYBOARD_H