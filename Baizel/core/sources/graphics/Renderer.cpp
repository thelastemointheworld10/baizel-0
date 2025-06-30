#include <graphics/Renderer.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	void iRenderer::SetClearColor(cColor aColor)
	{
		cLog::Log("New clear color: %d %d %d", aColor.r, aColor.g, aColor.b);
		mClearColor = aColor;
	}

	cColor iRenderer::GetClearColor() const
	{
		return mClearColor;
	}

	// -----------------------------------------------------------------------
}