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
	};
}

#endif // BAIZEL_TEXTURE_H