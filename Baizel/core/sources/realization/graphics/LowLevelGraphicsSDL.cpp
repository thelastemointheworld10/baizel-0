#include <realization/graphics/LowLevelGraphicsSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	cLowLevelGraphicsSDL::~cLowLevelGraphicsSDL()
	{
		if (mpWindow != nullptr)
		{
			SDL_DestroyWindow(mpWindow);
			mpWindow = nullptr;
		}
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	bool cLowLevelGraphicsSDL::Init(const char* asWindowTitle, tVector2l avWindowSize, bool abFullscreen)
	{
		unsigned int lFlags = SDL_WINDOW_SHOWN;
		if (abFullscreen) lFlags |= SDL_WINDOW_FULLSCREEN;

		mvScreenSize = avWindowSize;

		cLog::Log("Setting video mode: %d x %d with virtual size %.1f x %.1f",
			mvScreenSize.x, mvScreenSize.y, mvVirtualSize.x, mvVirtualSize.y);

		mpWindow = SDL_CreateWindow(asWindowTitle,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			mvScreenSize.x, mvScreenSize.y,
			lFlags);
		if (mpWindow == nullptr)
		{
			cLog::Fatal("Failed to create window: %s", SDL_GetError());
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