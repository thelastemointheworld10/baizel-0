#ifndef BAIZEL_VECTOR3_H
#define BAIZEL_VECTOR3_H

namespace baizel
{
	template <typename T>
	class cVector2; // for ToVec2

	template <typename T>
	class cVector3 final
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// CONSTRUCTORS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		cVector3() : x(T{}), y(T{}), z(T{})
		{
		}

		cVector3(T aValue) : x(aValue), y(aValue), z(aValue)
		{
		}

		cVector3(T aX, T aY) : x(aX), y(aY), z(T{})
		{
		}

		cVector3(T aX, T aY, T aZ) : x(aX), y(aY), z(aZ)
		{
		}

		cVector3(const cVector3<T>& avVector) : x(avVector.x), y(avVector.y), z(avVector.z)
		{
		}

		// -----------------------------------------------------------------------

		//////////////////////////////////////////////////////////////////////////
		// OPERATORS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Copy
		//////////////////////////////////////////

		inline cVector3<T>& operator=(const cVector3<T>& avVector)
		{
			x = avVector.x;
			y = avVector.y;
			z = avVector.z;

			return *this;
		}

		inline cVector3<T>& operator=(const T& aValue)
		{
			x = aValue;
			y = aValue;
			z = aValue;

			return *this;
		}

		//////////////////////////////////////////
		// Boolean
		//////////////////////////////////////////

		inline bool operator==(const cVector3<T>& avVector) const
		{
			return (x == avVector.x) && (y == avVector.y) && (z == avVector.z);
		}

		inline bool operator!=(const cVector3<T>& avVector) const
		{
			return (*this == avVector) == false;
		}

		//////////////////////////////////////////
		// Vector Arithmetic
		//////////////////////////////////////////

		inline cVector3<T> operator+(const cVector3<T>& avVector) const
		{
			return cVector3<T>(x + avVector.x, y + avVector.y, z + avVector.z);
		}

		inline cVector3<T> operator-(const cVector3<T>& avVector) const
		{
			return cVector3<T>(x - avVector.x, y - avVector.y, z - avVector.z);
		}

		inline cVector3<T> operator*(const cVector3<T>& avVector) const
		{
			return cVector3<T>(x * avVector.x, y * avVector.y, z * avVector.z);
		}

		inline cVector3<T> operator/(const cVector3<T>& avVector) const
		{
			return cVector3<T>(x / avVector.x, y / avVector.y, z / avVector.z);
		}

		inline cVector3<T>& operator+=(const cVector3<T>& avVector)
		{
			x += avVector.x;
			y += avVector.y;
			z += avVector.z;

			return *this;
		}

		inline cVector3<T>& operator-=(const cVector3<T>& avVector)
		{
			x -= avVector.x;
			y -= avVector.y;
			z -= avVector.z;

			return *this;
		}

		inline cVector3<T>& operator*=(const cVector3<T>& avVector)
		{
			x *= avVector.x;
			y *= avVector.y;
			z *= avVector.z;

			return *this;
		}

		inline cVector3<T>& operator/=(const cVector3<T>& avVector)
		{
			x /= avVector.x;
			y /= avVector.y;
			z /= avVector.z;

			return *this;
		}

		//////////////////////////////////////////
		// Real Arithmetic
		//////////////////////////////////////////

		inline cVector3<T> operator*(const T& aValue) const
		{
			return cVector3<T>(x * aValue, y * aValue, z * aValue);
		}

		inline cVector3<T> operator/(const T& aValue) const
		{
			return cVector3<T>(x / aValue, y / aValue, z / aValue);
		}

		inline cVector3<T> operator+(const T& aValue) const
		{
			return cVector3<T>(x + aValue, y + aValue, z + aValue);
		}

		inline cVector3<T> operator-(const T& aValue) const
		{
			return cVector3<T>(x - aValue, y - aValue, z - aValue);
		}

		// -----------------------------------------------------------------------

		//////////////////////////////////////////////////////////////////////////
		// PUBLIC METHODS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Core Functionality
		//////////////////////////////////////////

		inline cVector2<T> ToVec2() const
		{
			return cVector2<T>(x, y);
		}

		// -----------------------------------------------------------------------

		T x, y, z;
	};
}

#endif // BAIZEL_VECTOR3_H