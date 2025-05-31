#include <graphics/Color.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cColor::cColor(uint8_t alRed, uint8_t alGreen, uint8_t alBlue, uint8_t alAlpha) :
		r(alRed), g(alGreen), b(alBlue), a(alAlpha)
	{
		CheckValidValues(*this);
	}

	cColor::cColor(uint8_t alRed, uint8_t alGreen, uint8_t alBlue) :
		r(alRed), g(alGreen), b(alBlue), a(255)
	{
		CheckValidValues(*this);
	}

	cColor::cColor(uint8_t alRGB, uint8_t alAlpha) :
		r(alRGB), g(alRGB), b(alRGB), a(alAlpha)
	{
		CheckValidValues(*this);
	}

	cColor::cColor(uint8_t alRGBA) :
		r(alRGBA), g(alRGBA), b(alRGBA), a(alRGBA)
	{
		CheckValidValues(*this);
	}

	cColor::cColor(const cColor& avColor) :
		r(avColor.r), g(avColor.g), b(avColor.b), a(avColor.a)
	{ }

	cColor::cColor() :
		r(255), g(255), b(255), a(255)
	{ }

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	inline void cColor::CheckValidValues(cColor& aColor)
	{
		if (aColor.r > 255)
		{
			cLog::Warning("Red color is more than 255! Setting 255 by default");
			aColor.r = 255;
		}
		if (aColor.g > 255)
		{
			cLog::Warning("Green color is more than 255! Setting 255 by default");
			aColor.g = 255;
		}
		if (aColor.b > 255)
		{
			cLog::Warning("Blue color is more than 255! Setting 255 by default");
			aColor.b = 255;
		}
		if (aColor.a > 255)
		{
			cLog::Warning("Alpha channel is more than 255! Setting 255 by default");
			aColor.a = 255;
		}
	}

	// -----------------------------------------------------------------------
}