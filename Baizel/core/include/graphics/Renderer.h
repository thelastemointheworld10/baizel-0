#ifndef BAIZEL_RENDERER_H
#define BAIZEL_RENDERER_H

#include <graphics/LowLevelGraphics.h>
#include <graphics/Texture.h>

namespace baizel
{
	enum eRendererFlip
	{
		eRendererFlip_None,
		eRendererFlip_Horizontal,
		eRendererFlip_Vertical
	};

	class iRenderer
	{
	public:
		virtual ~iRenderer() = default;

		virtual bool Init(iLowLevelGraphics* apGraphics) = 0;

		virtual void SetDrawColor(const cColor& aColor) const = 0;
		virtual void Clear() const = 0;
		virtual void SwapBuffers() const = 0;

		virtual void DrawRect(const tVector2f& avPosition, const tVector2f& avSize, const cColor& aColor) const = 0;
		virtual void DrawFilledRect(const tVector2f& avPosition, const tVector2f& avSize, const cColor& aColor) const = 0;
		virtual void DrawTexture(iTexture* apTexture, const tVector2f& avPosition, const tVector2f& avSize,
			float afAngle = 0.0f, const tVector2f& avCenter = tVector2f(),
			eRendererFlip aTextureFlip = eRendererFlip_None) const = 0;
	};
}

#endif // BAIZEL_RENDERER_H