#ifndef BAIZEL_FONT_H
#define BAIZEL_FONT_H

#include <unordered_map>

#include <graphics/Glyph.h>

#include <graphics/LowLevelGraphics.h>
#include <graphics/Texture.h>

namespace baizel
{
	const int gkDefaultGlyphs = 351; // latin + cyrillic characters

	class cFontAtlas final
	{
	public:
		cFontAtlas(iLowLevelGraphics* apLowLevelGraphics);
		~cFontAtlas();

		void Load(const std::string& asPath);

		const std::string& GetPath() const;

	private:
		iLowLevelGraphics* mpLowLevelGraphics = nullptr;
		iTexture* mpTexture = nullptr;

		std::string msPath = " ";
		std::vector<cGlyph> mvGlyphs;
	};
}

#endif // BAIZEL_FONT_H