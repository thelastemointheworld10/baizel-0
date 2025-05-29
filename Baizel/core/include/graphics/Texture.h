#ifndef BAIZEL_TEXTURE_H
#define BAIZEL_TEXTURE_H

#include <string>

#include <graphics/Renderer.h>

namespace baizel
{
	class iTexture
	{
	public:
		virtual ~iTexture() = default;

		virtual void Load(std::string asPath) = 0;

		virtual void SetColor(uint8_t alR, uint8_t alG, uint8_t alB) const = 0;
		virtual void SetAlpha(uint8_t alA) const = 0;
	};
}

#endif // BAIZEL_TEXTURE_H