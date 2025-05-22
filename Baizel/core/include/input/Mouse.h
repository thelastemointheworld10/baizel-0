#ifndef BAIZEL_MOUSE_H
#define BAIZEL_MOUSE_H

#include <vector>

#include <input/InputDevice.h>
#include <input/InputTypes.h>

namespace baizel
{
	class iMouse : public iInputDevice
	{
	public:
		virtual bool GetButtonPressed(eMouseButton aKey) = 0;
	};
}

#endif // BAIZEL_MOUSE_H