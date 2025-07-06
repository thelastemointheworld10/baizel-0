#ifndef BAIZEL_RENDERER_H
#define BAIZEL_RENDERER_H

#include <math/MathTypes.h>

#include <graphics/LowLevelGraphics.h>
#include <graphics/Texture.h>
#include <graphics/Color.h>
#include <graphics/RectTypes.h>
#include <resources/FontAtlas.h>

namespace baizel
{
	enum eRendererFlip
	{
		eRendererFlip_None,
		eRendererFlip_Horizontal,
		eRendererFlip_Vertical
	};

	const cColor gkInvalidColor = cColor(199, 195, 187, 150);

	class iRenderer
	{
	public:
		virtual ~iRenderer() = default;

		virtual bool Init(iLowLevelGraphics* apGraphics) = 0;

		void SetClearColor(cColor aColor);
		cColor GetClearColor() const;

		virtual void ClearColor(cColor aColor) const = 0;
		virtual void Clear() const = 0;
		virtual void SwapBuffers() const = 0;

		virtual void DrawRect(tRectf aRect, cColor aColor) const = 0;
		virtual void DrawFilledRect(tRectf aRect, cColor aColor) const = 0;
		virtual void DrawTexture(iTexture* apTexture, tRectf aRect,
			float afAngle = 0.0f, tVector2f avCenter = tVector2f(),
			eRendererFlip aTextureFlip = eRendererFlip_None) const = 0;
		virtual void DrawTexture(iTexture* apTexture, tRectl aSourceRect, tRectf aDestRect,
			float afAngle = 0.0f, tVector2f avCenter = tVector2f(),
			eRendererFlip aTextureFlip = eRendererFlip_None) const = 0;

		void DrawText(const std::string& asText, cFontAtlas* apFontAtlas, int alSize, tVector2f avPosition, cColor aColor) const;

	protected:
		cColor mClearColor = cColor(0, 0, 0, 255); // black
	};
}

#endif // BAIZEL_RENDERER_H