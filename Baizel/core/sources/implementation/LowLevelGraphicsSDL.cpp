#include <implementation/LowLevelGraphicsSDL.h>
#include <SDL2/SDL_image.h>
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
		SDL_DestroyRenderer(mpRenderer);
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
			Fatal("Failed to create window: %s", SDL_GetError());
			return false;
		}

		mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED);
		if (mpRenderer == nullptr)
		{
			Fatal("Failed to create renderer: %s", SDL_GetError());
			return false;
		}
		SDL_SetRenderDrawColor(mpRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

		return true;
	}

	void cLowLevelGraphicsSDL::SetCursorVisible(bool abVisible)
	{
		SDL_ShowCursor(abVisible);
	}

	SDL_Texture* cLowLevelGraphicsSDL::LoadTexture(std::string asPath)
	{
		SDL_Texture* pResult;
		
		SDL_Surface* pLoadedSurface = IMG_Load(asPath.c_str());
		if (pLoadedSurface == nullptr)
		{
			Error("Failed to load texture '%s': %s", asPath.c_str(), IMG_GetError());
			return nullptr;
		}

		pResult = SDL_CreateTextureFromSurface(mpRenderer, pLoadedSurface);
		if (pLoadedSurface == nullptr)
		{
			Error("Failed to create texture from surface '%s': %s", asPath.c_str(), SDL_GetError());
			return nullptr;
		}

		SDL_FreeSurface(pLoadedSurface);

		return pResult;
	}

	// -----------------------------------------------------------------------
}