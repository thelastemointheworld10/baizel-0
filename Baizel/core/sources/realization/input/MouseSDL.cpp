#include <realization/input/MouseSDL.h>

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
		mvPressedButtons.clear();

		tVector2f vScreenSize = mpLowLevelGraphics->GetScreenSizeFloat();
		tVector2f vVirtualSize = mpLowLevelGraphics->GetVirtualSize();

		mvButtonArray[eMouseButton_WheelUp] = false;
		mvButtonArray[eMouseButton_WheelDown] = false;

		for (const auto& Event : mpLowLevelInputSDL->GetEvents())
		{
			if (Event.type != SDL_MOUSEBUTTONDOWN &&
				Event.type != SDL_MOUSEBUTTONUP &&
				Event.type != SDL_MOUSEMOTION &&
				Event.type != SDL_MOUSEWHEEL)
				continue;

			if (Event.type == SDL_MOUSEMOTION)
			{
				mvAbsolutePosition = tVector2f(Event.motion.x, Event.motion.y);
				mvAbsolutePosition = mvAbsolutePosition / vScreenSize * vVirtualSize;
			}
			else if (Event.type == SDL_MOUSEBUTTONDOWN || Event.type == SDL_MOUSEBUTTONUP)
			{
				eMouseButton Button = SDLToButton(Event.button.button);

				if (Event.type == SDL_MOUSEBUTTONDOWN)
				{
					mvButtonArray[Button] = true;
					mvPressedButtons.push_back(Button);

					continue;
				}

				mvButtonArray[Button] = false;
			}
			else if (Event.type == SDL_MOUSEWHEEL)
			{
				if (Event.wheel.y > 0)
					mvButtonArray[eMouseButton_WheelUp] = true;
				else if (Event.wheel.y < 0)
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

	bool cMouseSDL::GetButtonPressed(eMouseButton aKey) const
	{
		return mvButtonArray[aKey];
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	eMouseButton cMouseSDL::SDLToButton(int alButton) const
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