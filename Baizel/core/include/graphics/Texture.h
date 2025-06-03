#ifndef BAIZEL_TEXTURE_H
#define BAIZEL_TEXTURE_H

#include <string>

#include <graphics/Color.h>
#include <graphics/Renderer.h>
#include <graphics/Font.h>

namespace baizel
{
	class iTexture
	{
	public:
		virtual ~iTexture() = default;

		virtual void LoadFile(const std::string& asPath) = 0;
		virtual void CreateFromFont(iFont* aFont, const cColor& aColor) = 0;

		virtual void SetColor(uint8_t alR, uint8_t alG, uint8_t alB) const = 0;
		virtual void SetColor(const cColor& aColor) const = 0;
		virtual void SetAlpha(uint8_t alA) const = 0;

		inline const std::string& GetPath() const { return msPath; }

		virtual iTexture& operator=(const iTexture& aTexture) = 0;
	protected:
		std::string msPath = "";
	};
}

#endif // BAIZEL_TEXTURE_H