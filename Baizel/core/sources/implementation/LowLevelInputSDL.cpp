#include <implementation/LowLevelInputSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cLowLevelInputSDL::cLowLevelInputSDL(cEngine* apEngine)
	{
		mpEngine = apEngine;
	}

	cLowLevelInputSDL::~cLowLevelInputSDL()
	{
		Log("destructor of cLowLevelInputSDL called");
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	void cLowLevelInputSDL::Update()
	{
		UpdateEvents();
		UpdateKeyboard();
		UpdateMouse();
		UpdateJoystick();
	}

	void cLowLevelInputSDL::UpdateEvents()
	{
		while (SDL_PollEvent(&mEvent))
		{
			switch (mEvent.type)
			{
			case SDL_QUIT:
				mpEngine->Exit();
				break;
			}
		}
	}

	void cLowLevelInputSDL::UpdateKeyboard()
	{

	}

	void cLowLevelInputSDL::UpdateMouse()
	{

	}

	void cLowLevelInputSDL::UpdateJoystick()
	{

	}

	// -----------------------------------------------------------------------
}