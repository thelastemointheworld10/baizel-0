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
	}

	cColor::cColor(uint8_t alRed, uint8_t alGreen, uint8_t alBlue) :
		r(alRed), g(alGreen), b(alBlue), a(255)
	{
	}

	cColor::cColor(uint8_t alRGB, uint8_t alAlpha) :
		r(alRGB), g(alRGB), b(alRGB), a(alAlpha)
	{
	}

	cColor::cColor(uint8_t alRGBA) :
		r(alRGBA), g(alRGBA), b(alRGBA), a(alRGBA)
	{
	}

	cColor::cColor(const cColor& avColor) :
		r(avColor.r), g(avColor.g), b(avColor.b), a(avColor.a)
	{
	}

	cColor::cColor() :
		r(255), g(255), b(255), a(255)
	{
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// OPERATORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Boolean
	//////////////////////////////////////////

	bool cColor::operator==(cColor aColor) const
	{
		return (r == aColor.r) &&
			(g == aColor.g) &&
			(b == aColor.b) &&
			(a == aColor.a);
	}

	bool cColor::operator!=(cColor aColor) const
	{
		return (*this == aColor) == false;
	}

	bool cColor::operator==(uint8_t alRGBA) const
	{
		return (r == alRGBA) &&
			(g == alRGBA) &&
			(b == alRGBA) &&
			(a == alRGBA);
	}

	bool cColor::operator!=(uint8_t alRGBA) const
	{
		return (*this == alRGBA) == false;
	}

	//////////////////////////////////////////
	// Copy
	//////////////////////////////////////////

	cColor& cColor::operator=(cColor aColor)
	{
		r = aColor.r;
		g = aColor.g;
		b = aColor.b;
		a = aColor.a;

		return *this;
	}

	cColor& cColor::operator=(uint8_t alRGBA)
	{
		r = alRGBA;
		g = alRGBA;
		b = alRGBA;
		a = alRGBA;

		return *this;
	}

	//////////////////////////////////////////
	// Color Arithmetic
	//////////////////////////////////////////

	cColor cColor::operator+(cColor aColor) const
	{
		cColor Color(r + aColor.r, g + aColor.g, b + aColor.b, a + aColor.a);
		return Color;
	}

	cColor cColor::operator-(cColor aColor) const
	{
		cColor Color(r - aColor.r, g - aColor.g, b - aColor.b, a - aColor.a);
		return Color;
	}

	cColor cColor::operator*(cColor aColor) const
	{
		cColor Color(r * aColor.r, g * aColor.g, b * aColor.b, a * aColor.a);
		return Color;
	}

	cColor cColor::operator/(cColor aColor) const
	{
		cColor Color(r / aColor.r, g / aColor.g, b / aColor.b, a / aColor.a);
		return Color;
	}

	cColor& cColor::operator+=(cColor aColor)
	{
		r += aColor.r;
		g += aColor.g;
		b += aColor.b;
		a += aColor.a;

		return *this;
	}

	cColor& cColor::operator-=(cColor aColor)
	{
		r -= aColor.r;
		g -= aColor.g;
		b -= aColor.b;
		a -= aColor.a;

		return *this;
	}

	cColor& cColor::operator*=(cColor aColor)
	{
		r *= aColor.r;
		g *= aColor.g;
		b *= aColor.b;
		a *= aColor.a;

		return *this;
	}

	cColor& cColor::operator/=(cColor aColor)
	{
		r /= aColor.r;
		g /= aColor.g;
		b /= aColor.b;
		a /= aColor.a;

		return *this;
	}

	//////////////////////////////////////////
	// Real Arithmetic
	//////////////////////////////////////////

	cColor cColor::operator+(uint8_t alRGBA) const
	{
		cColor Color(r + alRGBA, g + alRGBA, b + alRGBA, a + alRGBA);
		return Color;
	}

	cColor cColor::operator-(uint8_t alRGBA) const
	{
		cColor Color(r - alRGBA, g - alRGBA, b - alRGBA, a - alRGBA);
		return Color;
	}

	cColor cColor::operator*(uint8_t alRGBA) const
	{
		cColor Color(r * alRGBA, g * alRGBA, b * alRGBA, a * alRGBA);
		return Color;
	}

	cColor cColor::operator/(uint8_t alRGBA) const
	{
		cColor Color(r / alRGBA, g / alRGBA, b / alRGBA, a / alRGBA);
		return Color;
	}

	cColor& cColor::operator+=(uint8_t alRGBA)
	{
		r += alRGBA;
		g += alRGBA;
		b += alRGBA;
		a += alRGBA;

		return *this;
	}

	cColor& cColor::operator-=(uint8_t alRGBA)
	{
		r -= alRGBA;
		g -= alRGBA;
		b -= alRGBA;
		a -= alRGBA;

		return *this;
	}

	cColor& cColor::operator*=(uint8_t alRGBA)
	{
		r *= alRGBA;
		g *= alRGBA;
		b *= alRGBA;
		a *= alRGBA;

		return *this;
	}

	cColor& cColor::operator/=(uint8_t alRGBA)
	{
		r /= alRGBA;
		g /= alRGBA;
		b /= alRGBA;
		a /= alRGBA;

		return *this;
	}

	// -----------------------------------------------------------------------
}