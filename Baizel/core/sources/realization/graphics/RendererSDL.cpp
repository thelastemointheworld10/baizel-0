#include <realization/graphics/RendererSDL.h>

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
			cLog::Fatal("Failed to create renderer: %s", SDL_GetError());

		tVector2f vVirtualSize = pLowLevelGraphicsSDL->GetVirtualSize();

		SDL_RenderSetLogicalSize(mpRenderer, vVirtualSize.x, vVirtualSize.y);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
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

	void cRendererSDL::DrawRect(float afX, float afY, float afW, float afH) const
	{
		SDL_FRect Rect;
		Rect.x = afX;
		Rect.y = afY;
		Rect.w = afW;
		Rect.h = afH;

		SDL_RenderDrawRectF(mpRenderer, &Rect);
	}

	void cRendererSDL::DrawFilledRect(float afX, float afY, float afW, float afH) const
	{
		SDL_FRect Rect;
		Rect.x = afX;
		Rect.y = afY;
		Rect.w = afW;
		Rect.h = afH;

		SDL_RenderFillRectF(mpRenderer, &Rect);
	}

	void cRendererSDL::DrawTexture(iTexture* apTexture, float afX, float afY, float afWidth, float afHeight) const
	{
		SDL_Texture* pSDLTexture = dynamic_cast<cTextureSDL*>(apTexture)->GetTexture();

		SDL_FRect Rect{ afX, afY, afWidth, afHeight };
		SDL_RenderCopyF(mpRenderer, pSDLTexture, nullptr, &Rect);
	}

	// -----------------------------------------------------------------------
}