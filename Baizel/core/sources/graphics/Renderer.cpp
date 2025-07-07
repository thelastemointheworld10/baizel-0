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

	//////////////////////////////////////////
	// Core Functionality
	//////////////////////////////////////////

	void iRenderer::DrawText(const std::string& asText, cFontAtlas* apFontAtlas, int alSize, tVector2f avPosition, cColor aColor) const
	{
		const float kfBaseSize = static_cast<float>(apFontAtlas->GetSize());
		const float kfScale = static_cast<float>(alSize) / kfBaseSize;

		tVector2f vCursorPos = avPosition;

		for (char lChar : asText)
		{
			const cGlyph& Glyph = apFontAtlas->GetGlyph(cUtf8Converter::Convert(lChar));

			const tVector2l& kvGlyphPos = Glyph.GetRect().GetPosition();
			const tVector2l& kvGlyphSize = Glyph.GetRect().GetSize();
			const tVector2l& kvGlyphOffset = Glyph.GetOffset();
			const float kfAdvance = Glyph.GetAdvance();

			tRectl SourceRect(kvGlyphPos, kvGlyphSize);

			tVector2f vDestPos(
				vCursorPos.x + static_cast<float>(kvGlyphOffset.x) * kfScale,
				vCursorPos.y + static_cast<float>(kvGlyphOffset.y) * kfScale
			);

			tVector2f vDestSize(
				static_cast<float>(kvGlyphSize.x) * kfScale,
				static_cast<float>(kvGlyphSize.y) * kfScale
			);

			tRectf DestRect(vDestPos, vDestSize);

			DrawTexture(apFontAtlas->GetPage(Glyph.GetPage()),
				SourceRect,
				DestRect);

			vCursorPos.x += kfAdvance * kfScale;
		}
	}

	// -----------------------------------------------------------------------
}