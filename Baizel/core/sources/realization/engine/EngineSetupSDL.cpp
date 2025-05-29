#include <realization/engine/EngineSetupSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cEngineSetupSDL::cEngineSetupSDL()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
			cLog::Fatal("Failed to initialize SDL: %s", SDL_GetError());
		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
			cLog::Fatal("IMG_Init failed: %s", IMG_GetError());

		cLog::Log("SDL Version: %d.%d.%d",
			SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);

		cLog::Log("SDL_image Version: %d.%d.%d",
			SDL_IMAGE_MAJOR_VERSION, SDL_IMAGE_MINOR_VERSION, SDL_IMAGE_PATCHLEVEL);

		cLog::Log("----------------------------------------------------");
	}

	cEngineSetupSDL::~cEngineSetupSDL()
	{
		cLog::Log("- Exiting SDL");

		cLog::Log("  SDL_image");
		IMG_Quit();
		cLog::Log("  SDL");
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

	cGraphics* cEngineSetupSDL::CreateGraphics() const
	{
		iRenderer* pRendererSDL = new cRendererSDL();
		iLowLevelGraphics* pLowLevelGraphicsSDL = new cLowLevelGraphicsSDL();

		return new cGraphics(pLowLevelGraphicsSDL, pRendererSDL);
	}

	cInput* cEngineSetupSDL::CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics) const
	{
		cLowLevelInputSDL* pLowLevelInputSDL = new cLowLevelInputSDL(apEngine);
		cInput* pInput = new cInput(pLowLevelInputSDL);

		iKeyboard* pKeyboard = new cKeyboardSDL(pLowLevelInputSDL);
		iMouse* pMouse = new cMouseSDL(pLowLevelInputSDL, apGraphics);

		pInput->SetDevice(eInputDeviceType_Keyboard, pKeyboard);
		pInput->SetDevice(eInputDeviceType_Mouse, pMouse);

		return pInput;
	}

	// -----------------------------------------------------------------------
}