#ifndef BAIZEL_MOUSE_H
#define BAIZEL_MOUSE_H

#include <math/MathTypes.h>

#include <graphics/LowLevelGraphics.h>
#include <input/InputDevice.h>
#include <input/InputTypes.h>

namespace baizel
{
	enum eMouseMode
	{
		eMouseMode_Free,
		eMouseMode_Relative
	};

	class iMouse : public iInputDevice
	{
	public:
		iMouse(iLowLevelGraphics* apLowLevelGraphics);

		virtual bool GetButtonPressed(eMouseButton aKey) const = 0;
		eMouseButton GetLastButton() const;

		tVector2f GetAbsolutePosition() const;
		tVector2f GetRelativePosition() const;

		virtual void SetCursorVisible(bool abVisible) const = 0;
		virtual void SetMouseMode(eMouseMode aMouseMode) const = 0;

	protected:
		tMouseButtonVector mvPressedButtons;

		tVector2f mvAbsolutePosition;
		tVector2f mvRelativePosition;

		iLowLevelGraphics* mpLowLevelGraphics;
	};
}

#endif // BAIZEL_MOUSE_H