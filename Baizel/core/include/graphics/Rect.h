#ifndef BAIZEL_RECT_H
#define BAIZEL_RECT_H

#include <math/Vector2.h>

namespace baizel
{
	template <typename T>
	class cRect final
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// PUBLIC METHODS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------
		
		cRect()
		{
		}

		cRect(cVector2<T> avPosition, cVector2<T> avSize)
		{
			mvPosition = avPosition;
			mvSize = avSize;
		}
		
		// -----------------------------------------------------------------------

		//////////////////////////////////////////////////////////////////////////
		// PUBLIC METHODS
		//////////////////////////////////////////////////////////////////////////

		// -----------------------------------------------------------------------

		//////////////////////////////////////////
		// Accessors
		//////////////////////////////////////////

		void SetPosition(cVector2<T> avPosition)
		{
			mvPosition = avPosition;
		}

		cVector2<T> GetPosition() const
		{
			return mvPosition;
		}

		void SetSize(cVector2<T> avSize)
		{
			mvSize = avSize;
		}

		cVector2<T> GetSize() const
		{
			return mvSize;
		}

		// -----------------------------------------------------------------------

	private:
		cVector2<T> mvPosition = cVector2<T>();
		cVector2<T> mvSize = cVector2<T>();
	};
}

#endif // BAIZEL_RECT_H