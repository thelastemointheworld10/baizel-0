#ifndef BAIZEL_TEXTURESDL_H
#define BAIZEL_TEXTURESDL_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/Log.h>

#include <graphics/Texture.h>
#include <impl/graphics/RendererSDL.h>

namespace baizel
{
	class cTextureSDL final : public iTexture
	{
	public:
		cTextureSDL(iRenderer* apRenderer);
		~cTextureSDL() override;

		void LoadFile(const std::string& asPath) override;

		inline void SetColor(uint8_t alR, uint8_t alG, uint8_t alB) const override;
		inline void SetColor(cColor aColor) const override;
		inline void SetAlpha(uint8_t alA) const override;

		SDL_Texture* GetTexture() const;

		iTexture& operator=(const iTexture& aTexture) override;

	private:
		bool CreateTextureFromSurface();
		void ReleaseResources();

	private:
		SDL_Surface* mpSurface = nullptr;
		SDL_Texture* mpTexture = nullptr;
		SDL_Renderer* mpRenderer = nullptr;
	};
}

#endif // BAIZEL_TEXTURESDL_H