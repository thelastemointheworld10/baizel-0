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

	iLowLevelGraphics* cGraphics::GetLowLevel()
	{
		return mpLowLevelGraphics;
	}

	iRenderer* cGraphics::GetRenderer()
	{
		return mpRenderer;
	}

	// -----------------------------------------------------------------------
}