#ifndef BAIZEL_TEXTURE_H
#define BAIZEL_TEXTURE_H

#include <string>

#include <graphics/Color.h>
#include <graphics/Renderer.h>

namespace baizel
{
	using tTextureVec = std::vector<iTexture*>;

	class iTexture
	{
	public:
		virtual ~iTexture() = default;

		virtual void LoadFile(const std::string& asPath) = 0;

		virtual void SetColor(uint8_t alR, uint8_t alG, uint8_t alB) const = 0;
		virtual void SetColor(cColor aColor) const = 0;
		virtual void SetAlpha(uint8_t alA) const = 0;

		const std::string& GetPath() const;
		tVector2l GetSize() const;
		void SetSize(tVector2l avSize);

		virtual iTexture& operator=(const iTexture& aTexture) = 0;

	protected:
		std::string msPath = "";
		tVector2l mvSize = tVector2l();
	};
}

#endif // BAIZEL_TEXTURE_H