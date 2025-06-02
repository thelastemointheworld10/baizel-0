#include <realization/graphics/FontSDL.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cFontSDL::cFontSDL(iLowLevelGraphics* apLowLevelGraphics, iRenderer* apRenderer)
		: iFont(apLowLevelGraphics, apRenderer)
	{ }

	cFontSDL::~cFontSDL()
	{
		TTF_CloseFont(mpFont);
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Resource Management
	//////////////////////////////////////////

	void cFontSDL::Load(const std::string& asPath)
	{
		mpFont = TTF_OpenFont(asPath.c_str(), mlSize);
		if (mpFont == nullptr)
		{
			cLog::Error("Failed to load font '%s'! %s", asPath.c_str(), TTF_GetError());
			return;
		}

		if (mpTexture == nullptr)
			mpTexture = mpLowLevelGraphics->CreateTexture();

		msPath = asPath;
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cFontSDL::Draw(const tVector2f& avPosition, const cColor& aColor)
	{
		if (mpFont == nullptr || msText.empty() || mpTexture == nullptr)
			return;

		mpTexture->LoadFont(this);
		mpTexture->SetColor(aColor);
		mpRenderer->DrawTexture(mpTexture, avPosition, GetTextSize());
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	tVector2f cFontSDL::GetTextSize() const
	{
		if (mpFont == nullptr || msText.empty())
			return tVector2f(0.0f);

		tVector2l vTextSize;
		tVector2f vVirtualSize;

		TTF_SizeText(mpFont, msText.c_str(), &vTextSize.x, &vTextSize.y);
		vVirtualSize = mpLowLevelGraphics->GetVirtualSize();

		float fTextW = static_cast<float>(vTextSize.x);
		float fTextH = static_cast<float>(vTextSize.y);

		return tVector2f(fTextW, fTextH);
	}

	void cFontSDL::SetSize(int alSize)
	{
		if (mlSize == alSize || mpFont == nullptr)
			return;

		mlSize = alSize;
		TTF_CloseFont(mpFont);
		mpFont = TTF_OpenFont(msPath.c_str(), mlSize);
	}

	TTF_Font* cFontSDL::GetFont() const
	{
		return mpFont;
	}

	// -----------------------------------------------------------------------
}