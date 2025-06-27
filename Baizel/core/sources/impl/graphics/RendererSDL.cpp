#include <impl/graphics/RendererSDL.h>

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

	void cRendererSDL::ClearColor(cColor aColor) const
	{
		SDL_SetRenderDrawColor(mpRenderer, aColor.r, aColor.g, aColor.b, aColor.a);
	}

	void cRendererSDL::Clear() const
	{
		SDL_RenderClear(mpRenderer);
	}

	void cRendererSDL::SwapBuffers() const
	{
		SDL_RenderPresent(mpRenderer);
	}

	void cRendererSDL::DrawRect(tRectf aRect, cColor aColor) const
	{
		tVector2f vPos = aRect.GetPosition();
		tVector2f vSize = aRect.GetSize();

		SDL_FRect Rect;
		Rect.x = vPos.x;
		Rect.y = vPos.y;
		Rect.w = vSize.x;
		Rect.h = vSize.y;

		ClearColor(aColor);
		SDL_RenderDrawRectF(mpRenderer, &Rect);
	}

	void cRendererSDL::DrawFilledRect(tRectf aRect, cColor aColor) const
	{
		tVector2f vPos = aRect.GetPosition();
		tVector2f vSize = aRect.GetSize();

		SDL_FRect Rect;
		Rect.x = vPos.x;
		Rect.y = vPos.y;
		Rect.w = vSize.x;
		Rect.h = vSize.y;

		ClearColor(aColor);
		SDL_RenderFillRectF(mpRenderer, &Rect);
	}

	void cRendererSDL::DrawTexture(iTexture* apTexture, tRectf aRect,
		float afAngle, tVector2f avCenter,
		eRendererFlip aTextureFlip) const
	{
		if (apTexture == nullptr)
		{
			DrawFilledRect(aRect, gkInvalidColor);
			return;
		}

		SDL_Texture* pSDLTexture = dynamic_cast<cTextureSDL*>(apTexture)->GetTexture();
		if (pSDLTexture == nullptr)
		{
			DrawFilledRect(aRect, gkInvalidColor);
			return;
		}

		tVector2f vPos = aRect.GetPosition();
		tVector2f vSize = aRect.GetSize();

		SDL_FRect Rect{ vPos.x, vPos.y, vSize.x, vSize.y };
		SDL_FPoint Center{ avCenter.x, avCenter.y };

		SDL_RenderCopyExF(mpRenderer, pSDLTexture, nullptr, &Rect, afAngle, &Center, (SDL_RendererFlip)aTextureFlip);
	}

	void cRendererSDL::DrawTexture(iTexture* apTexture, tRectl aSourceRect, tRectf aDestRect,
		float afAngle, tVector2f avCenter,
		eRendererFlip aTextureFlip) const
	{
		if (apTexture == nullptr)
		{
			DrawFilledRect(aDestRect, gkInvalidColor);
			return;
		}

		SDL_Texture* pSDLTexture = dynamic_cast<cTextureSDL*>(apTexture)->GetTexture();
		if (pSDLTexture == nullptr)
		{
			DrawFilledRect(aDestRect, gkInvalidColor);
			return;
		}

		tVector2l vSrcPos = aSourceRect.GetPosition();
		tVector2l vSrcSize = aSourceRect.GetSize();
		tVector2f vDestPos = aDestRect.GetPosition();
		tVector2f vDestSize = aDestRect.GetSize();

		SDL_Rect SourceRect{ vSrcPos.x, vSrcPos.y, vSrcSize.x, vSrcSize.y };
		SDL_FRect DestRect{ vDestPos.x, vDestPos.y, vDestSize.x, vDestSize.y };
		SDL_FPoint Center{ avCenter.x, avCenter.y };

		SDL_RenderCopyExF(mpRenderer, pSDLTexture, &SourceRect, &DestRect, afAngle, &Center, (SDL_RendererFlip)aTextureFlip);
	}

	// -----------------------------------------------------------------------
}