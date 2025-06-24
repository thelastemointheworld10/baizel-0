#include <graphics/Texture.h>

namespace baizel
{
	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	// -----------------------------------------------------------------------

	//////////////////////////////////////////
	// Accessors
	//////////////////////////////////////////

	const std::string& iTexture::GetPath() const
	{
		return msPath;
	}

	tVector2l iTexture::GetSize() const
	{
		return mvSize;
	}

	void iTexture::SetSize(tVector2l avSize)
	{
		mvSize = avSize;
	}

	// -----------------------------------------------------------------------
}