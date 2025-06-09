#include <realization/graphics/RendererSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cRendererSDL::~cRendererSDL()
	{
		if (mpRenderer != nullptr)
		{
			SDL_DestroyRenderer(mpRenderer);
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

	bool cRendererSDL::Init(iLowLevelGraphics* apGraphics)
	{
		cLowLevelGraphicsSDL* pLowLevelGraphicsSDL = dynamic_cast<cLowLevelGraphicsSDL*>(apGraphics);

		mpRenderer = SDL_CreateRenderer(pLowLevelGraphicsSDL->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
		if (mpRenderer == nullptr)
		{
			cLog::Fatal("Failed to create renderer: %s", SDL_GetError());
			return false;
		}

		tVector2f vVirtualSize = pLowLevelGraphicsSDL->GetVirtualSize();

		SDL_RenderSetLogicalSize(mpRenderer, vVirtualSize.x, vVirtualSize.y);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

		return true;
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

	void cRendererSDL::DrawRect(const tVector2f& avPosition, const tVector2f& avSize, const cColor& aColor) const
	{
		SDL_FRect Rect;
		Rect.x = avPosition.x;
		Rect.y = avPosition.y;
		Rect.w = avSize.x;
		Rect.h = avSize.y;

		SDL_SetRenderDrawColor(mpRenderer, aColor.r, aColor.g, aColor.b, aColor.a);
		SDL_RenderDrawRectF(mpRenderer, &Rect);
	}

	void cRendererSDL::DrawFilledRect(const tVector2f& avPosition, const tVector2f& avSize, const cColor& aColor) const
	{
		SDL_FRect Rect;
		Rect.x = avPosition.x;
		Rect.y = avPosition.y;
		Rect.w = avSize.x;
		Rect.h = avSize.y;

		SDL_SetRenderDrawColor(mpRenderer, aColor.r, aColor.g, aColor.b, aColor.a);
		SDL_RenderFillRectF(mpRenderer, &Rect);
	}

	void cRendererSDL::DrawTexture(iTexture* apTexture, const tVector2f& avPosition, const tVector2f& avSize,
		float afAngle, const tVector2f& avCenter,
		eRendererFlip aTextureFlip) const
	{
		SDL_Texture* pSDLTexture = dynamic_cast<cTextureSDL*>(apTexture)->GetTexture();

		SDL_FRect Rect{ avPosition.x, avPosition.y, avSize.x, avSize.y };
		SDL_FPoint Center{ avCenter.x, avCenter.y };

		SDL_RenderCopyExF(mpRenderer, pSDLTexture, nullptr, &Rect, afAngle, &Center, (SDL_RendererFlip)aTextureFlip);
	}

	// -----------------------------------------------------------------------
}