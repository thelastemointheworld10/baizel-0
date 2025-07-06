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

		// pages
		cXMLNode* pPages = pRoot->FindChildByName("pages");
		tNodeListIt PagesIt = pPages->GetChildren().begin();
		for (; PagesIt != pPages->GetChildren().end(); ++ PagesIt)
		{
			const std::string& sFile = (*PagesIt)->ToElement()->GetAttributeString("file");
			cLog::Log("Trying to load page file: '%s'", sFile.c_str());
			
			mvPages.push_back(mpLowLevelGraphics->CreateTexture());
			mvPages.back()->LoadFile(sFile);
		}

		// characters
		cXMLNode* pChars = pRoot->FindChildByName("chars");
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

			//cLog::Log("test xpos %d", mmapGlyphs[lID].GetRect().GetPosition());
		}

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

	const cGlyph& cFontAtlas::GetGlyph(int alIndex) const
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
}