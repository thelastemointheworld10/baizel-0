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
			Fatal("Failed to initialize SDL2: %s", SDL_GetError());
		if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0)
			Fatal("Failed to initialize SDL2_image: %s", IMG_GetError());

		Log("SDL Version: %d.%d.%d", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
	}

	cSDLGameSetup::~cSDLGameSetup()
	{
		SDL_Quit();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cGraphics* cSDLGameSetup::CreateGraphics()
	{
		return new cGraphics(new cLowLevelGraphicsSDL());
	}

	iLowLevelInput* cSDLGameSetup::CreateInput(cEngine* apEngine)
	{
		return new cLowLevelInputSDL(apEngine);
	}

	// -----------------------------------------------------------------------
}