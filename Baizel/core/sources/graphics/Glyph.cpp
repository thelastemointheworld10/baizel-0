#include <graphics/Glyph.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	tRectl cGlyph::GetRect() const
	{
		return mRect;
	}

	tVector2f cGlyph::GetOffset() const
	{
		return mvOffset;
	}

	void cGlyph::SetOffset(tVector2f avOffset)
	{
		mvOffset = avOffset;
	}

	float cGlyph::GetAdvance() const
	{
		return mfAdvance;
	}

	void cGlyph::SetAdvance(float afAdvance)
	{
		mfAdvance = afAdvance;

		if (mfAdvance == 0.0f)
			mfAdvance = 0.0f;
	}

	int cGlyph::GetPage() const
	{
		return mlPage;
	}

	void cGlyph::SetPage(int alPage)
	{
		mlPage = alPage;

		if (mlPage == 0)
			mlPage = 1;
	}

	// -----------------------------------------------------------------------
}