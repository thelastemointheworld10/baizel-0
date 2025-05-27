#ifndef BAIZEL_RENDERER_H
#define BAIZEL_RENDERER_H

#include <graphics/LowLevelGraphics.h>

namespace baizel
{
	class iRenderer
	{
	public:
		virtual ~iRenderer() = default;

		virtual void Init(iLowLevelGraphics* apGraphics) = 0;

		virtual void SetDrawColor(uint8_t alR, uint8_t alG, uint8_t alB, uint8_t alA = 255) const = 0;
		virtual void Clear() const = 0;
		virtual void SwapBuffers() const = 0;

		virtual void Copy(iTexture* apTexture) const = 0;
		virtual void DrawRect(float afX, float afY, float afW, float afH) const = 0;
		virtual void DrawFilledRect(float afX, float afY, float afW, float afH) const = 0;
	};
}

#endif // BAIZEL_RENDERER_H