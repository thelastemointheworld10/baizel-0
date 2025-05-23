#include <realization/EngineSetupSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cEngineSetupSDL::cEngineSetupSDL()
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

	cEngineSetupSDL::~cEngineSetupSDL()
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

	cGraphics* cEngineSetupSDL::CreateGraphics()
	{
		iRenderer* pRendererSDL = new cRendererSDL();
		iLowLevelGraphics* pLowLevelGraphicsSDL = new cLowLevelGraphicsSDL(pRendererSDL);

		return new cGraphics(pLowLevelGraphicsSDL);
	}

	cInput* cEngineSetupSDL::CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics)
	{
		cLowLevelInputSDL* pLowLevelInputSDL = new cLowLevelInputSDL(apEngine);
		cInput* pInput = new cInput(pLowLevelInputSDL);

		iKeyboard* pKeyboard = new cKeyboardSDL(pLowLevelInputSDL);
		iMouse* pMouse = new cMouseSDL(pLowLevelInputSDL, apGraphics);

		pInput->SetKeyboard(pKeyboard);
		pInput->SetMouse(pMouse);

		return pInput;
	}

	// -----------------------------------------------------------------------
}