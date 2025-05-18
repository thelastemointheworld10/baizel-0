#include <implementation/TextureSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	cTextureSDL::cTextureSDL(iRenderer* apRenderer)
	{
		mpRenderer = dynamic_cast<cRendererSDL*>(apRenderer)->GetRenderer();
	}

	cTextureSDL::~cTextureSDL()
	{
		SDL_DestroyTexture(mpTexture);
		mpTexture = nullptr;
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	void cTextureSDL::Load(std::string asPath)
	{
		SDL_Surface* pLoadedSurface = IMG_Load(asPath.c_str());
		if (pLoadedSurface == nullptr)
		{
			Error("Failed to load texture '%s': %s", asPath.c_str(), IMG_GetError());
			return;
		}

		mpTexture = SDL_CreateTextureFromSurface(mpRenderer, pLoadedSurface);
		if (mpTexture == nullptr)
			Error("Failed to create texture from surface '%s': %s", asPath.c_str(), SDL_GetError());

		SDL_FreeSurface(pLoadedSurface);
	}

	SDL_Texture* cTextureSDL::GetTexture() const
	{
		return mpTexture;
	}

	// -----------------------------------------------------------------------
}