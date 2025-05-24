#ifndef BAIZEL_KEYBOARD_H
#define BAIZEL_KEYBOARD_H

#include <vector>

#include <input/InputDevice.h>
#include <input/InputTypes.h>

namespace baizel
{
	class iKeyboard : public iInputDevice
	{
	public:
		iKeyboard();

		virtual bool GetAnyKeyPressed() = 0;
		virtual bool GetKeyPressed(eKey aKey) = 0;
		eKey GetLastKey();

	protected:
		std::vector<eKey> mvPressedKeys;
	};
}

#endif // BAIZEL_KEYBOARD_H