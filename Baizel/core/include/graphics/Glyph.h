#ifndef BAIZEL_GLYPH_H
#define BAIZEL_GLYPH_H

#include <graphics/RectTypes.h>
#include <math/MathTypes.h>

namespace baizel
{
	class cGlyph final
	{
	public:
		cGlyph();
		cGlyph(tVector2l avPos, tVector2l avSize, tVector2l avOffset, int alAdvance, int alPage);

		tRectl GetRect() const;

		tVector2l GetOffset() const;
		void SetOffset(tVector2l avOffset);

		float GetAdvance() const;
		void SetAdvance(int alAdvance);

		int GetPage() const;
		void SetPage(int alPage);

	private:
		tRectl mRect = tRectl();
		tVector2l mvOffset = tVector2l();
		int mlAdvance = 10;
		int mlPage = 0;
	};
}

#endif // BAIZEL_GLYPH_H