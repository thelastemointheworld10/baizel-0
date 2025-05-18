#include <implementation/RendererSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cRendererSDL::~cRendererSDL()
	{
		SDL_DestroyRenderer(mpRenderer);
		mpRenderer = nullptr;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	SDL_Renderer* cRendererSDL::GetRenderer() const
	{
		return mpRenderer;
	}

	void cRendererSDL::Init(iLowLevelGraphics* apGraphics)
	{
		cLowLevelGraphicsSDL* pGraphicsSDL = dynamic_cast<cLowLevelGraphicsSDL*>(apGraphics);

		mpRenderer = SDL_CreateRenderer(pGraphicsSDL->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
		if (mpRenderer == nullptr)
			Fatal("Failed to create renderer: %s", SDL_GetError());
	}

	void cRendererSDL::SetDrawColor(uint8_t alR, uint8_t alG, uint8_t alB, uint8_t alA) const
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