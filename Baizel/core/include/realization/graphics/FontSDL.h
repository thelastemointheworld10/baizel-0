#ifndef BAIZEL_FONTSDL_H
#define BAIZEL_FONTSDL_H

#include <SDL2/SDL_ttf.h>

#include <realization/graphics/TextureSDL.h>
#include <graphics/Font.h>

namespace baizel
{
	class cFontSDL final : public iFont
	{
	public:
		cFontSDL(iLowLevelGraphics* apLowLevelGraphics, iRenderer* apRenderer);
		~cFontSDL();

		void Load(const std::string& asPath) override;
		void Draw(const tVector2f& avPosition, const cColor& aColor) override;
		
		tVector2f GetTextSize() const override;
		void SetSize(int alSize) override;

		TTF_Font* GetFont() const;

	private:
		TTF_Font* mpFont = nullptr;
		iTexture* mpTexture = nullptr;
	};
}

#endif // BAIZEL_FONTSDL_H