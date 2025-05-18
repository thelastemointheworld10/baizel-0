#ifndef BAIZEL_RENDERERSDL_H
#define BAIZEL_RENDERERSDL_H

#include <string>

#include <SDL2/SDL.h>

#include <Log.h>

#include <interfaces/Renderer.h>
#include <implementation/LowLevelGraphicsSDL.h>

namespace baizel
{
	class cRendererSDL final : public iRenderer
	{
	public:
		~cRendererSDL() override;

		SDL_Renderer* GetRenderer() const;

		void Init(iLowLevelGraphics* apGraphics) override;

		void SetDrawColor(uint8_t alR, uint8_t alG, uint8_t alB, uint8_t alA = 255) const override;
		void Clear() const override;
		void SwapBuffers() const override;

		void Copy(iTexture* apTexture) const override;

	private:
		SDL_Renderer* mpRenderer = nullptr;
	};
}

#endif // BAIZEL_RENDERERSDL_H