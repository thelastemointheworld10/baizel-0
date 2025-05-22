#include <realization/LowLevelGraphicsSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cLowLevelGraphicsSDL::cLowLevelGraphicsSDL(iRenderer* apRenderer)
		: iLowLevelGraphics(apRenderer)
	{ }
	
	cLowLevelGraphicsSDL::~cLowLevelGraphicsSDL()
	{
		if (mpWindow != nullptr)
		{
			SDL_DestroyWindow(mpWindow);
			mpWindow = nullptr;
		}

		delete mpRenderer;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	bool cLowLevelGraphicsSDL::Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen)
	{
		unsigned int lFlags = SDL_WINDOW_SHOWN;
		if (abFullscreen == true) lFlags |= SDL_WINDOW_FULLSCREEN;

		mpWindow = SDL_CreateWindow(asWindowTitle,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			avWindowSize.x, avWindowSize.y,
			lFlags);
		if (mpWindow == nullptr)
		{
			Fatal("Failed to create window: %s", SDL_GetError());
			return false;
		}

		mpRenderer->Init(this);

		return true;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	SDL_Window* cLowLevelGraphicsSDL::GetWindow() const
	{
		return mpWindow;
	}

	iRenderer* cLowLevelGraphicsSDL::GetRenderer() const
	{
		return mpRenderer;
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cLowLevelGraphicsSDL::SetCursorVisible(bool abVisible) const
	{
		SDL_ShowCursor(abVisible);
	}

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	iTexture* cLowLevelGraphicsSDL::CreateTexture() const
	{
		return new cTextureSDL(mpRenderer);
	}

	// -----------------------------------------------------------------------
}