#include <implementation/Graphics.h>
#include <Log.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cGraphics::cGraphics(iLowLevelGraphics* apLowLevelGraphics)
	{
		mpLowLevelGraphics = apLowLevelGraphics;
	}

	cGraphics::~cGraphics()
	{
		delete mpLowLevelGraphics;
		mpLowLevelGraphics = nullptr;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	bool cGraphics::Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen)
	{
		if (mpLowLevelGraphics->Init(asWindowTitle, avWindowSize, abFullscreen) == false)
			return false;

		return true;
	}

	void cGraphics::DrawRect(uint8_t alRed, uint8_t alGreen, uint8_t alBlue, uint8_t alAlpha)
	{
		Log("DrawRect called");
	}

	void cGraphics::DrawTexturedRect(SDL_Texture* apTexture, uint8_t alAlpha)
	{
		Log("DrawTexturedRect called");
	}

	// -----------------------------------------------------------------------
}