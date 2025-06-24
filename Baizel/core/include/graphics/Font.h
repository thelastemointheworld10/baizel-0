#ifndef BAIZEL_FONT_H
#define BAIZEL_FONT_H

#include <math/MathTypes.h>

#include <graphics/Graphics.h>
#include <graphics/Color.h>

namespace baizel
{
	enum eTextAlign
	{
		eTextAlign_Left,
		eTextAlign_Right,
		eTextAlign_Center
	};

	class iFont
	{
	public:
		iFont(iLowLevelGraphics* apLowLevelGraphics, iRenderer* apRenderer);
		~iFont();

		virtual void Load(const std::string& asPath) = 0;
		virtual void Draw(tVector2f avPosition, cColor aColor, eTextAlign aTextAlign) = 0;

		virtual void SetSize(int alSize) = 0;
		virtual tVector2f GetTextSize() const = 0;

		const std::string& GetText() const;
		void SetText(const char* asFormat, ...);

	protected:
		iLowLevelGraphics* mpLowLevelGraphics = nullptr;
		iRenderer* mpRenderer = nullptr;
		iTexture* mpTexture = nullptr;

		std::string msPath;

		std::string msText = " ";
		std::string msLastText = " ";

		int mlSize = 12;
	};
}

#endif // BAIZEL_FONT_H