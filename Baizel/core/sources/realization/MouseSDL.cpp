#include <realization/MouseSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cMouseSDL::cMouseSDL(cLowLevelInputSDL* apLowLevelInputSDL)
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
		for (const auto& rEvent : mpLowLevelInputSDL->GetEvents())
		{
			if (rEvent.type != SDL_MOUSEBUTTONDOWN && rEvent.type != SDL_MOUSEBUTTONUP)
				continue;

			eMouseButton Key = SDLToButton(rEvent.button.button);
			mvButtonArray[Key] = rEvent.type == SDL_MOUSEBUTTONDOWN;
		}
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