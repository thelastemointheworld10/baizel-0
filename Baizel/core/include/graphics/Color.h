#ifndef BAIZEL_COLOR_H
#define BAIZEL_COLOR_H

#include <cstdint>

#include <engine/Log.h>

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

		inline cColor& operator=(const cColor& aColor)
		{
			r = aColor.r;
			g = aColor.g;
			b = aColor.b;
			a = aColor.a;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator=(uint8_t alRGBA)
		{
			r = alRGBA;
			g = alRGBA;
			b = alRGBA;
			a = alRGBA;
			CheckValidValues(*this);

			return *this;
		}

		//////////////////////////////////////////
		// Color Arithmetic
		//////////////////////////////////////////

		inline bool operator==(const cColor& aColor)
		{
			return (r == aColor.r) &&
				(g == aColor.g) &&
				(b == aColor.b) &&
				(a == aColor.a);
		}

		inline bool operator!=(const cColor& aColor)
		{
			return (*this == aColor) == false;
		}

		inline cColor operator+(const cColor& aColor)
		{
			cColor Color(r + aColor.r, g + aColor.g, b + aColor.b, a + aColor.a);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor operator-(const cColor& aColor)
		{
			cColor Color(r - aColor.r, g - aColor.g, b - aColor.b, a - aColor.a);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor operator*(const cColor& aColor)
		{
			cColor Color(r * aColor.r, g * aColor.g, b * aColor.b, a * aColor.a);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor operator/(const cColor& aColor)
		{
			cColor Color(r / aColor.r, g / aColor.g, b / aColor.b, a / aColor.a);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor& operator+=(const cColor& aColor)
		{
			r += aColor.r;
			g += aColor.g;
			b += aColor.b;
			a += aColor.a;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator-=(const cColor& aColor)
		{
			r -= aColor.r;
			g -= aColor.g;
			b -= aColor.b;
			a -= aColor.a;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator*=(const cColor& aColor)
		{
			r *= aColor.r;
			g *= aColor.g;
			b *= aColor.b;
			a *= aColor.a;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator/=(const cColor& aColor)
		{
			r /= aColor.r;
			g /= aColor.g;
			b /= aColor.b;
			a /= aColor.a;
			CheckValidValues(*this);

			return *this;
		}

		//////////////////////////////////////////
		// Real Arithmetic
		//////////////////////////////////////////

		inline bool operator==(uint8_t alRGBA)
		{
			return (r == alRGBA) &&
				(g == alRGBA) &&
				(b == alRGBA) &&
				(a == alRGBA);
		}

		inline bool operator!=(uint8_t alRGBA)
		{
			return (*this == alRGBA) == false;
		}

		inline cColor operator+(uint8_t alRGBA)
		{
			cColor Color(r + alRGBA, g + alRGBA, b + alRGBA, a + alRGBA);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor operator-(uint8_t alRGBA)
		{
			cColor Color(r - alRGBA, g - alRGBA, b - alRGBA, a - alRGBA);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor operator*(uint8_t alRGBA)
		{
			cColor Color(r * alRGBA, g * alRGBA, b * alRGBA, a * alRGBA);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor operator/(uint8_t alRGBA)
		{
			cColor Color(r / alRGBA, g / alRGBA, b / alRGBA, a / alRGBA);
			CheckValidValues(Color);

			return Color;
		}

		inline cColor& operator+=(uint8_t alRGBA)
		{
			r += alRGBA;
			g += alRGBA;
			b += alRGBA;
			a += alRGBA;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator-=(uint8_t alRGBA)
		{
			r -= alRGBA;
			g -= alRGBA;
			b -= alRGBA;
			a -= alRGBA;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator*=(uint8_t alRGBA)
		{
			r *= alRGBA;
			g *= alRGBA;
			b *= alRGBA;
			a *= alRGBA;
			CheckValidValues(*this);

			return *this;
		}

		inline cColor& operator/=(uint8_t alRGBA)
		{
			r /= alRGBA;
			g /= alRGBA;
			b /= alRGBA;
			a /= alRGBA;
			CheckValidValues(*this);

			return *this;
		}

		// -----------------------------------------------------------------------

		uint8_t r, g, b, a;

	private:
		inline void CheckValidValues(cColor& aColor);
	};
}

#endif // BAIZEL_COLOR_H