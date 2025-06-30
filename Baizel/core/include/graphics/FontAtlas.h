#ifndef BAIZEL_FONT_H
#define BAIZEL_FONT_H

#include <vector>

#include <graphics/Glyph.h>

#include <graphics/LowLevelGraphics.h>
#include <graphics/Texture.h>

namespace baizel
{
	const int gkDefaultGlyphs = 351; // latin + cyrillic characters
	const int gkDefaultPages = 2;

	class cFontAtlas final
	{
	public:
		cFontAtlas(iLowLevelGraphics* apLowLevelGraphics);
		~cFontAtlas();

		void LoadFile(const std::string& asPath);

		const std::string& GetPath() const;

	private:
		void ReadValues();
		void ReadPages();

	private:
		iLowLevelGraphics* mpLowLevelGraphics = nullptr;
		tTextureVec mvPages = tTextureVec();

		std::string msPath = " ";
		std::vector<cGlyph> mvGlyphs;
	};
}

#endif // BAIZEL_FONT_H