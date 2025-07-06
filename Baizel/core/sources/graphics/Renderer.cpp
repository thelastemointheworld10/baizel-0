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

		for (size_t i = 0; i < asText.size();)
		{
			unsigned char lChar = asText[i];
			int lCharCode = 0;
			int lBytes = 1;

			if ((lChar & 0x80) == 0) // ascii
			{
				lCharCode = lChar;
			}
			else if ((lChar & 0xE0) == 0xC0 && i + 1 < asText.length()) // cyrillic 2 bytes
			{
				lCharCode = ((lChar & 0x1F) << 6) | (asText[i + 1] & 0x3F);
				lBytes = 2;
			}
			else if ((lChar & 0xF0) == 0xE0 && i + 2 < asText.size()) // 3 bytes
			{
				lCharCode = ((lChar & 0x0F) << 12) | ((asText[i + 1] & 0x3F) << 6) | (asText[i + 2] & 0x3F);
				lBytes = 3;
			}

			i += lBytes;

			const cGlyph& Glyph = apFontAtlas->GetGlyph(lCharCode);

			const tVector2l kvGlyphPos = Glyph.GetRect().GetPosition();
			const tVector2l kvGlyphSize = Glyph.GetRect().GetSize();
			const tVector2l kvGlyphOffset = Glyph.GetOffset();
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