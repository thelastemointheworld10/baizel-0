#include <graphics/Graphics.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	cGraphics::cGraphics(iLowLevelGraphics* apLowLevelGraphics, iRenderer* apRenderer)
	{
		mpLowLevelGraphics = apLowLevelGraphics;
		mpRenderer = apRenderer;

		mpLowLevelGraphics->SetRenderer(mpRenderer);
		mpLowLevelGraphics->SetVirtualSize(tVector2f(800.0f, 600.0f));
	}

	cGraphics::~cGraphics()
	{
		delete mpRenderer;
		mpRenderer = nullptr;
	}

	// -----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	iLowLevelGraphics* cGraphics::GetLowLevel() const
	{
		return mpLowLevelGraphics;
	}

	iRenderer* cGraphics::GetRenderer() const
	{
		return mpRenderer;
	}

	// -----------------------------------------------------------------------
}