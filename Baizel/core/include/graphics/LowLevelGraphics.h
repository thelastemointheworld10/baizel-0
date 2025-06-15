#ifndef BAIZEL_LOWLEVELGRAPHICS_H
#define BAIZEL_LOWLEVELGRAPHICS_H

#include <string>

#include <math/MathTypes.h>

namespace baizel
{
    class iRenderer;
    class iTexture;
    class iFont;

    const tVector2l gkMinScreenSize = tVector2l(640, 480);
    const tVector2f gkMinVirtualSize = tVector2f(1, 1);

    class iLowLevelGraphics
    {
    public:
        virtual ~iLowLevelGraphics() = default;
        
        virtual bool Init(const std::string& asWindowTitle, tVector2l avWindowSize, tVector2f avVirtualSize, bool abFullscreen) = 0;

        void SetRenderer(iRenderer* apRenderer);
        tVector2f GetScreenSizeFloat() const;
        tVector2f GetVirtualSize() const;

        virtual iTexture* CreateTexture() const = 0;
        virtual iFont* CreateFont() = 0;

        virtual void SetCursorVisible(bool abVisible) const = 0;

    protected:
        iRenderer* mpRenderer = nullptr;

		tVector2l mvScreenSize = tVector2l(800, 600);
		tVector2f mvVirtualSize = tVector2f(800, 600);
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICS_H