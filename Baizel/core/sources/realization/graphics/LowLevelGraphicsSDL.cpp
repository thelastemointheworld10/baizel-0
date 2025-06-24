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

		delete mpRenderer;
		mpRenderer = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	bool cLowLevelGraphicsSDL::Init(const std::string& asWindowTitle, tVector2l avWindowSize, tVector2f avVirtualSize, bool abFullscreen)
	{
		unsigned int lFlags = SDL_WINDOW_SHOWN;
		if (abFullscreen) lFlags |= SDL_WINDOW_FULLSCREEN;

		mvScreenSize = avWindowSize;
		mvVirtualSize = avVirtualSize;

		cLog::Log("Setting video mode: %d x %d with virtual size %.1f x %.1f",
			mvScreenSize.x, mvScreenSize.y, mvVirtualSize.x, mvVirtualSize.y);

		mpWindow = SDL_CreateWindow(asWindowTitle.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			mvScreenSize.x, mvScreenSize.y,
			lFlags);
		if (mpWindow == nullptr)
		{
			cLog::Fatal("Failed to create window: %s", SDL_GetError());
			return false;
		}

		if (mpRenderer->Init(this) == false)
		{
			cLog::Fatal("Failed to init renderer!");
			return false;
		}

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
	// Resource Management
	//////////////////////////////////////////

	iTexture* cLowLevelGraphicsSDL::CreateTexture() const
	{
		return new cTextureSDL(mpRenderer);
	}

	iFont* cLowLevelGraphicsSDL::CreateFont()
	{
		return new cFontSDL(this, mpRenderer);
	}

	// -----------------------------------------------------------------------
}