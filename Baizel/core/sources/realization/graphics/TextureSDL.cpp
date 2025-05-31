#include <realization/graphics/TextureSDL.h>

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

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cTextureSDL::Load(const std::string& asPath)
	{
		if (mpTexture != nullptr)
		{
			SDL_DestroyTexture(mpTexture);
			mpTexture = nullptr;
		}

		SDL_Surface* pLoadedSurface = IMG_Load(asPath.c_str());
		if (pLoadedSurface == nullptr)
		{
			cLog::Error("Failed to load texture '%s': %s", asPath.c_str(), IMG_GetError());
			return;
		}

		mpTexture = SDL_CreateTextureFromSurface(mpRenderer, pLoadedSurface);
		if (mpTexture == nullptr)
			cLog::Error("Failed to create texture from surface '%s': %s", asPath.c_str(), SDL_GetError());
		else
			SDL_SetTextureBlendMode(mpTexture, SDL_BLENDMODE_BLEND);

		msPath = asPath;

		SDL_FreeSurface(pLoadedSurface);
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	inline void cTextureSDL::SetColor(uint8_t alR, uint8_t alG, uint8_t alB) const
	{
		SDL_SetTextureColorMod(mpTexture, alR, alG, alB);
	}

	inline void cTextureSDL::SetColor(const cColor& aColor) const
	{
		SDL_SetTextureColorMod(mpTexture, aColor.r, aColor.g, aColor.b);
	}

	inline void cTextureSDL::SetAlpha(uint8_t alA) const
	{
		SDL_SetTextureAlphaMod(mpTexture, alA);
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	SDL_Texture* cTextureSDL::GetTexture() const
	{
		return mpTexture;
	}

	// -----------------------------------------------------------------------
}