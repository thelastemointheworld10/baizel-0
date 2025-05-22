#include <realization/RendererSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cRendererSDL::~cRendererSDL()
	{
		SDL_DestroyRenderer(mpRenderer);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cRendererSDL::Init(iLowLevelGraphics* apGraphics)
	{
		cLowLevelGraphicsSDL* pLowLevelGraphicsSDL = dynamic_cast<cLowLevelGraphicsSDL*>(apGraphics);

		mpRenderer = SDL_CreateRenderer(pLowLevelGraphicsSDL->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
		if (mpRenderer == nullptr)
			Fatal("Failed to create renderer: %s", SDL_GetError());

		SDL_RenderSetLogicalSize(mpRenderer,
			pLowLevelGraphicsSDL->GetVirtualSize().x,
			pLowLevelGraphicsSDL->GetVirtualSize().y);
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	SDL_Renderer* cRendererSDL::GetRenderer() const
	{
		return mpRenderer;
	}

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void cRendererSDL::SetClearColor(uint8_t alR, uint8_t alG, uint8_t alB, uint8_t alA) const
	{
		SDL_SetRenderDrawColor(mpRenderer, alR, alG, alB, alA);
	}

	void cRendererSDL::Clear() const
	{
		SDL_RenderClear(mpRenderer);
	}

	void cRendererSDL::SwapBuffers() const
	{
		SDL_RenderPresent(mpRenderer);
	}

	void cRendererSDL::Copy(iTexture* apTexture) const
	{
		cTextureSDL* pTextureSDL = dynamic_cast<cTextureSDL*>(apTexture);
		SDL_RenderCopy(mpRenderer, pTextureSDL->GetTexture(), nullptr, nullptr);
	}

	// -----------------------------------------------------------------------
}