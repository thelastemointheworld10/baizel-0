#ifndef BAIZEL_RENDERERSDL_H
#define BAIZEL_RENDERERSDL_H

#include <string>

#include <SDL2/SDL.h>

#include <diagnostics/Log.h>

#include <graphics/Renderer.h>
#include <impl/graphics/LowLevelGraphicsSDL.h>

namespace baizel
{
	class cRendererSDL final : public iRenderer
	{
	public:
		~cRendererSDL() override;

		bool Init(iLowLevelGraphics* apGraphics) override;

		SDL_Renderer* GetRenderer() const;

		void ClearColor(cColor aColor) const override;
		void Clear() const override;
		void SwapBuffers() const override;

		void DrawRect(tRectf aRect, cColor aColor) const override;
		void DrawFilledRect(tRectf aRect, cColor aColor) const override;
		void DrawTexture(iTexture* apTexture, tRectf aRect,
			float afAngle = 0.0f, tVector2f avCenter = tVector2f(),
			eRendererFlip aTextureFlip = eRendererFlip_None) const override;
		void DrawTexture(iTexture* apTexture, tRectl aSourceRect, tRectf aDestRect,
			float afAngle = 0.0f, tVector2f avCenter = tVector2f(),
			eRendererFlip aTextureFlip = eRendererFlip_None) const override;

	private:
		SDL_Renderer* mpRenderer = nullptr;
	};
}

#endif // BAIZEL_RENDERERSDL_H