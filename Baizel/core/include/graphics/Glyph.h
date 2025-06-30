#ifndef BAIZEL_GLYPH_H
#define BAIZEL_GLYPH_H

#include <graphics/RectTypes.h>
#include <math/MathTypes.h>

namespace baizel
{
	class cGlyph final
	{
	public:
		tRectl GetRect() const;

		tVector2f GetOffset() const;
		void SetOffset(tVector2f avOffset);

		float GetAdvance() const;
		void SetAdvance(float afAdvance);

		int GetPage() const;
		void SetPage(int alPage);

	private:
		tRectl mRect = tRectl();
		tVector2f mvOffset = tVector2f();
		int mlAdvance = 10;
		int mlPage = 0;
	};
}

#endif // BAIZEL_GLYPH_H