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
		ReleaseResources();
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cTextureSDL::LoadFile(const std::string& asPath)
	{
		ReleaseResources();

		mpSurface = IMG_Load(asPath.c_str());
		if (mpSurface == nullptr)
		{
			cLog::Error("Failed to load texture '%s': %s", asPath.c_str(), IMG_GetError());
			return;
		}

		if (CreateTextureFromSurface())
			msPath = asPath;
	}

	void cTextureSDL::CreateFromFont(iFont* aFont, const cColor& aColor)
	{
		ReleaseResources();

		cFontSDL* pFontSDL = dynamic_cast<cFontSDL*>(aFont);
		if (pFontSDL == nullptr) return;

		mpSurface = TTF_RenderText_Blended(pFontSDL->GetFont(),
			pFontSDL->GetText().c_str(),
			{ aColor.r, aColor.g, aColor.b });
		
		if (mpSurface == nullptr)
		{
			cLog::Error("Failed to create font surface: %s", TTF_GetError());
			return;
		}

		CreateTextureFromSurface();
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

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------
	
	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	bool cTextureSDL::CreateTextureFromSurface()
	{
		if (mpSurface == nullptr || mpRenderer == nullptr)
			return false;

		if (mpTexture != nullptr)
		{
			SDL_DestroyTexture(mpTexture);
			mpTexture = nullptr;
		};

		mpTexture = SDL_CreateTextureFromSurface(mpRenderer, mpSurface);
		if (mpTexture == nullptr)
		{
			cLog::Error("Failed to create texture from surface: %s", SDL_GetError());
			return false;
		}
		SDL_SetTextureBlendMode(mpTexture, SDL_BLENDMODE_BLEND);

		return true;
	}

	void cTextureSDL::ReleaseResources()
	{
		if (mpTexture != nullptr)
		{
			SDL_DestroyTexture(mpTexture);
			mpTexture = nullptr;
		}
		if (mpSurface != nullptr)
		{
			SDL_FreeSurface(mpSurface);
			mpSurface = nullptr;
		}
	}
	
	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// OPERATORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Copy
	//////////////////////////////////////////

	iTexture& cTextureSDL::operator=(const iTexture& aTexture)
	{
		if (this == &aTexture)
			return *this;

		std::string sPath = aTexture.GetPath();
		if (sPath == "") // no texture
			return *this;

		LoadFile(sPath); // load texture from path
	}

	// -----------------------------------------------------------------------
}