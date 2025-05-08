#include <implementation/SDLGameSetup.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cSDLGameSetup::cSDLGameSetup()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
			Error("Failed to initialize SDL2: %s", SDL_GetError());
		Log("SDL Version: %d.%d.%d", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
	}

	cSDLGameSetup::~cSDLGameSetup()
	{
		Log("destructor of cSDLGameSetup called");

		SDL_Quit();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	iLowLevelGraphics* cSDLGameSetup::CreateGraphics()
	{
		return new cLowLevelGraphicsSDL();
	}

	iLowLevelInput* cSDLGameSetup::CreateInput(cEngine* apEngine)
	{
		return new cLowLevelInputSDL(apEngine);
	}

	// -----------------------------------------------------------------------
}