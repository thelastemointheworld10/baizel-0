#include <graphics/LowLevelGraphics.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void iLowLevelGraphics::SetRenderer(iRenderer* apRenderer)
	{
		mpRenderer = apRenderer;
	}

	tVector2f iLowLevelGraphics::GetScreenSizeFloat()
	{
		return tVector2f((float)mvScreenSize.x, (float)mvScreenSize.y);
	}

	tVector2f iLowLevelGraphics::GetVirtualSize()
	{
		return mvVirtualSize;
	}

	// -----------------------------------------------------------------------
}