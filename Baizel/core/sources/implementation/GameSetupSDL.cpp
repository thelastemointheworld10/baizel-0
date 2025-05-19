#include <implementation/GameSetupSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cSDLGameSetup::cSDLGameSetup()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
			Fatal("Failed to initialize SDL: %s", SDL_GetError());
		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
			Fatal("IMG_Init failed: %s", IMG_GetError());

		Log("SDL Version: %d.%d.%d",
			SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);

		Log("SDL_image Version: %d.%d.%d",
			SDL_IMAGE_MAJOR_VERSION, SDL_IMAGE_MINOR_VERSION, SDL_IMAGE_PATCHLEVEL);
	}

	cSDLGameSetup::~cSDLGameSetup()
	{
		Log("- Exiting SDL");

		Log("  SDL_image");
		IMG_Quit();
		Log("  SDL");
		SDL_Quit();
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	iLowLevelGraphics* cSDLGameSetup::CreateGraphics()
	{
		return new cLowLevelGraphicsSDL();
	}

	cInput* cSDLGameSetup::CreateInput()
	{
		cInput* pInput = new cInput(new cLowLevelInputSDL());
		pInput->SetKeyboard(new cKeyboardSDL());

		return pInput;
	}

	// -----------------------------------------------------------------------
}