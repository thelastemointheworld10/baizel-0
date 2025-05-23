#include <realization/MouseSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cMouseSDL::cMouseSDL(cLowLevelInputSDL* apLowLevelInputSDL, iLowLevelGraphics* apLowLevelGraphics)
		: iMouse(apLowLevelGraphics)
	{
		mpLowLevelInputSDL = apLowLevelInputSDL;

		mvButtonArray.resize(eMouseButton_Count);
		mvButtonArray.assign(mvButtonArray.size(), false);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cMouseSDL::Update()
	{
		tVector2f vScreenSize = mpLowLevelGraphics->GetScreenSizeFloat();
		tVector2f vVirtualSize = mpLowLevelGraphics->GetVirtualSize();

		mvButtonArray[eMouseButton_WheelUp] = false;
		mvButtonArray[eMouseButton_WheelDown] = false;

		for (const auto& rEvent : mpLowLevelInputSDL->GetEvents())
		{
			if (rEvent.type != SDL_MOUSEBUTTONDOWN &&
				rEvent.type != SDL_MOUSEBUTTONUP &&
				rEvent.type != SDL_MOUSEMOTION &&
				rEvent.type != SDL_MOUSEWHEEL)
				continue;

			if (rEvent.type == SDL_MOUSEMOTION)
			{
				mvAbsolutePosition = tVector2f(rEvent.motion.x, rEvent.motion.y);
				mvAbsolutePosition = mvAbsolutePosition / vScreenSize * vVirtualSize;
			}
			else if (rEvent.type == SDL_MOUSEBUTTONDOWN || rEvent.type == SDL_MOUSEBUTTONUP)
			{
				eMouseButton Key = SDLToButton(rEvent.button.button);
				mvButtonArray[Key] = (rEvent.type == SDL_MOUSEBUTTONDOWN);
			}
			else if (rEvent.type == SDL_MOUSEWHEEL)
			{
				if (rEvent.wheel.y > 0)
					mvButtonArray[eMouseButton_WheelUp] = true;
				else if (rEvent.wheel.y < 0)
					mvButtonArray[eMouseButton_WheelDown] = true;
			}
		}

		int lRelativeX;
		int lRelativeY;

		SDL_GetRelativeMouseState(&lRelativeX, &lRelativeY);

		mvRelativePosition = tVector2f(lRelativeX, lRelativeY);
		mvRelativePosition = mvRelativePosition / vScreenSize * vVirtualSize;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	bool cMouseSDL::GetButtonPressed(eMouseButton aKey)
	{
		return mvButtonArray[aKey];
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	eMouseButton cMouseSDL::SDLToButton(int alButton)
	{
		switch (alButton)
		{
		case SDL_BUTTON_LEFT:	return eMouseButton_Left;
		case SDL_BUTTON_MIDDLE: return eMouseButton_Middle;
		case SDL_BUTTON_RIGHT:	return eMouseButton_Right;

		default:				return eMouseButton_None;
		}
	}

	// -----------------------------------------------------------------------
}