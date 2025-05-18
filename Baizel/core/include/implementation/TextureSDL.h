#ifndef BAIZEL_TEXTURESDL_H
#define BAIZEL_TEXTURESDL_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Log.h>

#include <interfaces/Texture.h>
#include <implementation/RendererSDL.h>

namespace baizel
{
	class cTextureSDL final : public iTexture
	{
	public:
		cTextureSDL(iRenderer* apRenderer);
		~cTextureSDL() override;

		void Load(std::string asPath) override;

		SDL_Texture* GetTexture() const;

	private:
		SDL_Texture* mpTexture = nullptr;
		SDL_Renderer* mpRenderer = nullptr;
	};
}

#endif // BAIZEL_TEXTURESDL_H