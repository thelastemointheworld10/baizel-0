#include <resources/FontAtlas.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cFontAtlas::cFontAtlas(iLowLevelGraphics* apLowLevelGraphics, iXMLReader* apXMLReader)
	{
		mpLowLevelGraphics = apLowLevelGraphics;
		mpDocument = apXMLReader->CreateDocument();
	}

	cFontAtlas::~cFontAtlas()
	{
		for (iTexture* pPage : mvPages)
		{
			delete pPage;
		}
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	bool cFontAtlas::LoadFile(const std::string& asPath)
	{
		if (mpDocument->LoadFile(asPath) == false)
		{
			cLog::Error("Failed to load font atlass %s", asPath);
			return false;
		}

		msPath = asPath;

		cXMLElement* pRoot = mpDocument->GetFirstChild()->ToElement();
		LoadPages(pRoot);
		LoadChars(pRoot);

		return true;
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	const std::string& cFontAtlas::GetPath() const
	{
		return msPath;
	}

	iTexture* cFontAtlas::GetPage(int alIndex) const
	{
		if (alIndex > mvPages.size() || alIndex < 0)
		{
			cLog::Error("Page with index %d does not exists in font atlas %s", alIndex, msPath.c_str());
			return nullptr;
		}

		return mvPages[alIndex];
	}

	const cGlyph& cFontAtlas::GetGlyph(std::uint8_t alIndex) const
	{
		tGlyphMapIt it = mmapGlyphs.find(alIndex);
		if (it == mmapGlyphs.end())
		{
			//cLog::Error("Glyph with index %d does not exists in font atlas %s", alIndex, msPath.c_str());
			static const cGlyph skEmptyGlyph = cGlyph();
			return skEmptyGlyph;
		}

		return (*it).second;
	}

	int cFontAtlas::GetSize() const
	{
		return mlSize;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cFontAtlas::LoadPages(cXMLElement* apRoot)
	{
		cXMLNode* pPages = apRoot->FindChildByName("pages");
		tNodeListIt PagesIt = pPages->GetChildren().begin();

		for (; PagesIt != pPages->GetChildren().end(); ++PagesIt)
		{
			const std::string& sFile = (*PagesIt)->ToElement()->GetAttributeString("file");

			mvPages.push_back(mpLowLevelGraphics->CreateTexture());
			if (mvPages.back()->LoadFile(sFile) == false)
				cLog::Error("Failed to load font atlas page: %s", sFile.c_str());
			else
				cLog::Log("Font atlas page loaded: %s", sFile.c_str());
		}
	}

	void cFontAtlas::LoadChars(cXMLElement* apRoot)
	{
		cXMLNode* pChars = apRoot->FindChildByName("chars");
		tNodeListIt CharsIt = pChars->GetChildren().begin();

		for (; CharsIt != pChars->GetChildren().end(); ++CharsIt)
		{
			cXMLElement* pCharElem = (*CharsIt)->ToElement();

			int lID = pCharElem->GetAttributeInt("id");
			tVector2l vPos = tVector2l(
				pCharElem->GetAttributeInt("x"),
				pCharElem->GetAttributeInt("y"));
			tVector2l vSize = tVector2l(
				pCharElem->GetAttributeInt("width"),
				pCharElem->GetAttributeInt("height"));
			tVector2l vOffset = tVector2l(
				pCharElem->GetAttributeInt("xoffset"),
				pCharElem->GetAttributeInt("yoffset"));
			int lAdvance = pCharElem->GetAttributeInt("xadvance");
			int lPage = pCharElem->GetAttributeInt("page");

			cGlyph Glyph = cGlyph(vPos, vSize, vOffset, lAdvance, lPage);
			mmapGlyphs[lID] = Glyph;
		}
	}

	// -----------------------------------------------------------------------
}