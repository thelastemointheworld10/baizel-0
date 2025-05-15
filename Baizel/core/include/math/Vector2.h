#ifndef BAIZEL_VECTOR2_H
#define BAIZEL_VECTOR2_H

namespace baizel
{
	template <typename T>
	class cVector2 final
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// CONSTRUCTORS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		cVector2() : x(T{}), y(T{})
		{}

		cVector2(T aValue) : x(aValue), y(aValue)
		{}

		cVector2(T aX, T aY) : x(aX), y(aY)
		{}

		cVector2(const cVector2<T>& avVector) : x(avVector.x), y(avVector.y)
		{}

		// -----------------------------------------------------------------------

		//////////////////////////////////////////////////////////////////////////
		// OPERATORS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Copy
		//////////////////////////////////////////

		inline cVector2<T>& operator=(const cVector2<T>& avVector)
		{
			x = avVector.x;
			y = avVector.y;

			return *this;
		}

		inline cVector2<T>& operator=(const T aValue)
		{
			x = aValue;
			y = aValue;

			return *this;
		}

		//////////////////////////////////////////
		// Boolean
		//////////////////////////////////////////

		inline bool operator==(const cVector2<T>& avVector) const
		{
			return (x == avVector.x) && (y == avVector.y);
		}

		inline bool operator!=(const cVector2<T>& avVector) const
		{
			return (*this == avVector) == false;
		}

		//////////////////////////////////////////
		// Vector Arithmetic
		//////////////////////////////////////////

		inline cVector2<T> operator+(const cVector2<T>& avVector) const
		{
			return cVector2<T>(x + avVector.x, y + avVector.y);
		}

		inline cVector2<T> operator-(const cVector2<T>& avVector) const
		{
			return cVector2<T>(x - avVector.x, y - avVector.y);
		}

		inline cVector2<T> operator*(const cVector2<T>& avVector) const
		{
			return cVector2<T>(x * avVector.x, y * avVector.y);
		}

		inline cVector2<T> operator/(const cVector2<T>& avVector) const
		{
			return cVector2<T>(x / avVector.x, y / avVector.y);
		}

		inline cVector2<T>& operator+=(const cVector2<T>& avVector)
		{
			x += avVector.x;
			y += avVector.y;

			return *this;
		}

		inline cVector2<T>& operator-=(const cVector2<T>& avVector)
		{
			x -= avVector.x;
			y -= avVector.y;

			return *this;
		}

		inline cVector2<T>& operator*=(const cVector2<T>& avVector)
		{
			x *= avVector.x;
			y *= avVector.y;

			return *this;
		}

		inline cVector2<T>& operator/=(const cVector2<T>& avVector)
		{
			x /= avVector.x;
			y /= avVector.y;

			return *this;
		}

		//////////////////////////////////////////
		// Real Arithmetic
		//////////////////////////////////////////

		inline cVector2<T> operator+(const T& aValue) const
		{
			cVector2<T> Vector2;
			Vector2.x += aValue;
			Vector2.y += aValue;

			return Vector2;
		}

		inline cVector2<T> operator-(const T& aValue) const
		{
			cVector2<T> Vector2;
			Vector2.x -= aValue;
			Vector2.y -= aValue;

			return Vector2;
		}

		inline cVector2<T> operator*(const T& aValue) const
		{
			cVector2<T> Vector2;
			Vector2.x *= aValue;
			Vector2.y *= aValue;

			return Vector2;
		}

		inline cVector2<T> operator/(const T& aValue) const
		{
			cVector2<T> Vector2;
			Vector2.x /= aValue;
			Vector2.y /= aValue;

			return Vector2;
		}

		// -----------------------------------------------------------------------

		T x;
		T y;
	};
}

#endif // BAIZEL_VECTOR2_H