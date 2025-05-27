#include <input/Mouse.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	iMouse::iMouse(iLowLevelGraphics* apLowLevelGraphics)
	{
		mpLowLevelGraphics = apLowLevelGraphics;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	tVector2f iMouse::GetAbsolutePosition() const
	{
		return mvAbsolutePosition;
	}

	tVector2f iMouse::GetRelativePosition() const
	{
		return mvRelativePosition;
	}

	eMouseButton iMouse::GetLastButton() const
	{
		if (mvPressedButtons.empty())
			return eMouseButton_None;

		return mvPressedButtons[0];
	}

	// -----------------------------------------------------------------------
}