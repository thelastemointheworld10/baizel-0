#include <implementation/LowLevelGraphicsSDL.h>
#include <Log.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	cLowLevelGraphicsSDL::~cLowLevelGraphicsSDL()
	{
		SDL_DestroyWindow(mpWindow);
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

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
			Error("Failed to create window: %s", SDL_GetError());
			return false;
		}

		return true;
	}

	void cLowLevelGraphicsSDL::SetCursorVisible(bool abVisible)
	{
		SDL_ShowCursor(abVisible);
	}

	// -----------------------------------------------------------------------
}