#ifndef BAIZEL_MOUSE_H
#define BAIZEL_MOUSE_H

#include <math/MathTypes.h>

#include <graphics/LowLevelGraphics.h>
#include <input/InputDevice.h>
#include <input/InputTypes.h>

namespace baizel
{
	class iMouse : public iInputDevice
	{
	public:
		iMouse(iLowLevelGraphics* apLowLevelGraphics);

		virtual bool GetButtonPressed(eMouseButton aKey) = 0;

		tVector2f GetAbsolutePosition();
		tVector2f GetRelativePosition();

	protected:
		tVector2f mvAbsolutePosition;
		tVector2f mvRelativePosition;

		iLowLevelGraphics* mpLowLevelGraphics;
	};
}

#endif // BAIZEL_MOUSE_H