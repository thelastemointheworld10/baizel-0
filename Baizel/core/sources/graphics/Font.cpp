#include <graphics/Font.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	iFont::iFont(iLowLevelGraphics* apLowLevelGraphics, iRenderer* apRenderer)
	{
		mpLowLevelGraphics = apLowLevelGraphics;
		mpRenderer = apRenderer;
	}

	iFont::~iFont()
	{
		delete mpTexture;
		mpTexture = nullptr;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	const std::string& iFont::GetText() const
	{
		return msText;
	}

	void iFont::SetText(const char* asFormat, ...)
	{
		if (asFormat == nullptr)
			return;

		msLastText = msText;

		va_list pArgs;
		va_start(pArgs, asFormat);
		msText = cLog::GetFormatedString(asFormat, pArgs);
		va_end(pArgs);
	}

	// -----------------------------------------------------------------------
}