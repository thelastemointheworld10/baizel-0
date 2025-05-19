#ifndef BAIZEL_KEYBOARD_H
#define BAIZEL_KEYBOARD_H

#include <vector>

#include <interfaces/InputDevice.h>
#include <InputTypes.h>

namespace baizel
{
	class iKeyboard : public iInputDevice
	{
	public:
		virtual bool GetAnyKeyPressed() = 0;
		virtual bool GetKeyDown(eKey aKey) = 0;
	};
}

#endif // BAIZEL_KEYBOARD_H