#ifndef BAIZEL_COLOR_H
#define BAIZEL_COLOR_H

#include <cstdint>

#include <diagnostics/Log.h>

namespace baizel
{
	class cColor final
	{
	public:
		cColor(uint8_t alRed, uint8_t alGreen, uint8_t alBlue, uint8_t alAlpha);
		cColor(uint8_t alRed, uint8_t alGreen, uint8_t alBlue);
		cColor(uint8_t alRGB, uint8_t alAlpha);
		cColor(uint8_t alRGBA);
		cColor(const cColor& avColor);
		cColor();

		//////////////////////////////////////////////////////////////////////////
		// OPERATORS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Copy
		//////////////////////////////////////////

		cColor& operator=(cColor aColor);
		cColor& operator=(uint8_t alRGBA);

		//////////////////////////////////////////
		// Color Arithmetic
		//////////////////////////////////////////

		bool operator==(cColor aColor) const;
		bool operator!=(cColor aColor) const;

		cColor operator+(cColor aColor) const;
		cColor operator-(cColor aColor) const;
		cColor operator*(cColor aColor) const;
		cColor operator/(cColor aColor) const;

		cColor& operator+=(cColor aColor);
		cColor& operator-=(cColor aColor);
		cColor& operator*=(cColor aColor);
		cColor& operator/=(cColor aColor);

		//////////////////////////////////////////
		// Real Arithmetic
		//////////////////////////////////////////

		bool operator==(uint8_t alRGBA) const;
		bool operator!=(uint8_t alRGBA) const;

		cColor operator+(uint8_t alRGBA) const;
		cColor operator-(uint8_t alRGBA) const;
		cColor operator*(uint8_t alRGBA) const;
		cColor operator/(uint8_t alRGBA) const;

		cColor& operator+=(uint8_t alRGBA);
		cColor& operator-=(uint8_t alRGBA);
		cColor& operator*=(uint8_t alRGBA);
		cColor& operator/=(uint8_t alRGBA);

		// -----------------------------------------------------------------------

		uint8_t r, g, b, a;
	};
}

#endif // BAIZEL_COLOR_H