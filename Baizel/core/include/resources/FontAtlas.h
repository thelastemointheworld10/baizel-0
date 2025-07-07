#ifndef BAIZEL_FONTATLAS_H
#define BAIZEL_FONTATLAS_H

#include <map>
#include <cstdint>

#include <graphics/Texture.h>
#include <graphics/Glyph.h>

#include <graphics/LowLevelGraphics.h>

#include <resources/XMLReader.h>

namespace baizel
{
	const int gkDefaultGlyphs = 351; // latin + cyrillic characters
	const int gkDefaultPages = 2;

	using tGlyphMap = std::map<std::uint8_t, cGlyph>;
	using tGlyphMapIt = tGlyphMap::const_iterator;

	class cFontAtlas final
	{
	public:
		cFontAtlas(iLowLevelGraphics* apLowLevelGraphics, iXMLReader* apXMLReader);
		~cFontAtlas();

		bool LoadFile(const std::string& asPath);

		const std::string& GetPath() const;
		iTexture* GetPage(int alIndex) const;
		const cGlyph& GetGlyph(std::uint8_t alIndex) const;
		int GetSize() const;

	private:
		void LoadPages(cXMLElement* apRoot);
		void LoadChars(cXMLElement* apRoot);

	private:
		iLowLevelGraphics* mpLowLevelGraphics = nullptr;
		iXMLDocument* mpDocument = nullptr;

		std::vector<iTexture*> mvPages;
		tGlyphMap mmapGlyphs;

		std::string msPath = "";
		int mlSize = 32;
	};
}

#endif // BAIZEL_FONTATLAS_H