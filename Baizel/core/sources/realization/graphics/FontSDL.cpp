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

		msPath = asPath;
	}

	//////////////////////////////////////////
	// Runtime Control
	//////////////////////////////////////////

	void cFontSDL::Draw(tVector2f avPosition, const cColor& aColor, eTextAlign aTextAlign)
	{
		if (mpFont == nullptr || msText.empty())
			return;

		if (mpTexture == nullptr)
			mpTexture = mpLowLevelGraphics->CreateTexture();
		
		// Creating a new texture only if the text has been updated
		if (msText != msLastText)
		{
			mpTexture->CreateFromFont(this, aColor);
			msLastText = msText;
			//cLog::Log("Font texture updated");
		}

		tVector2f vTextSize = GetTextSize();

		switch (aTextAlign)
		{
		case eTextAlign_Center:
			avPosition.x -= vTextSize.x / 2;
			break;
		case eTextAlign_Left:
			avPosition.x -= vTextSize.x;
			break;
		case eTextAlign_Right:
			// We leave it as it is
			break;
		}

		mpRenderer->DrawTexture(mpTexture, avPosition, vTextSize);
	}

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	tVector2f cFontSDL::GetTextSize() const
	{
		if (mpFont == nullptr || msText.empty())
			return tVector2f(0.0f);

		tVector2l vTextSize;
		TTF_SizeText(mpFont, msText.c_str(), &vTextSize.x, &vTextSize.y);

		float fTextW = static_cast<float>(vTextSize.x);
		float fTextH = static_cast<float>(vTextSize.y);
		//cLog::Log("Text Size: %f, %f", fTextW, fTextH);

		return tVector2f(fTextW, fTextH);
	}

	void cFontSDL::SetSize(int alSize)
	{
		if (mlSize == alSize || mpFont == nullptr)
			return;

		mlSize = alSize;
		TTF_CloseFont(mpFont);
		mpFont = TTF_OpenFont(msPath.c_str(), mlSize);

		// I'm resetting the last text so that the texture is updated.
		msLastText = "";
	}

	TTF_Font* cFontSDL::GetFont() const
	{
		return mpFont;
	}

	// -----------------------------------------------------------------------
}