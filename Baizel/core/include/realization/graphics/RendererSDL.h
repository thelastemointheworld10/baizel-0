#ifndef BAIZEL_RENDERERSDL_H
#define BAIZEL_RENDERERSDL_H

#include <string>

#include <SDL2/SDL.h>

#include <engine/Log.h>

#include <graphics/Renderer.h>
#include <realization/graphics/LowLevelGraphicsSDL.h>

namespace baizel
{
	class cRendererSDL final : public iRenderer
	{
	public:
		~cRendererSDL() override;

		bool Init(iLowLevelGraphics* apGraphics) override;

		SDL_Renderer* GetRenderer() const;

		void SetDrawColor(const cColor& aColor) const override;
		void Clear() const override;
		void SwapBuffers() const override;

		void DrawRect(const tVector2f& avPosition, const tVector2f& avSize, const cColor& aColor) const override;
		void DrawFilledRect(const tVector2f& avPosition, const tVector2f& avSize, const cColor& aColor) const override;
		void DrawTexture(iTexture* apTexture, const tVector2f& avPosition, const tVector2f& avSize,
			float afAngle = 0.0f, const tVector2f& avCenter = tVector2f(),
			eRendererFlip aTextureFlip = eRendererFlip_None) const override;

	private:
		SDL_Renderer* mpRenderer = nullptr;
	};
}

#endif // BAIZEL_RENDERERSDL_H