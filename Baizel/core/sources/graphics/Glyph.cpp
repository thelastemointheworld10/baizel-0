#include <graphics/Glyph.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cGlyph::cGlyph()
	{
	}

	cGlyph::cGlyph(tVector2l avPos, tVector2l avSize, tVector2l avOffset, int alAdvance, int alPage)
	{
		mRect.SetPosition(avPos);
		mRect.SetSize(avSize);
		mvOffset = avOffset;
		mlAdvance = alAdvance;
		mlPage = alPage;
	}

	// -----------------------------------------------------------------------

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

	tVector2l cGlyph::GetOffset() const
	{
		return mvOffset;
	}

	void cGlyph::SetOffset(tVector2l avOffset)
	{
		mvOffset = avOffset;
	}

	float cGlyph::GetAdvance() const
	{
		return mlAdvance;
	}

	void cGlyph::SetAdvance(int alAdvance)
	{
		mlAdvance = alAdvance;

		if (mlAdvance < 0)
			mlAdvance = 0;
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