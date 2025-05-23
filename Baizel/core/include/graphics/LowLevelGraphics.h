#ifndef BAIZEL_LOWLEVELGRAPHICS_H
#define BAIZEL_LOWLEVELGRAPHICS_H

#include <string>

#include <math/MathTypes.h>

namespace baizel
{
    class iRenderer;
    class iTexture;

    class iLowLevelGraphics
    {
    public:
        iLowLevelGraphics(iRenderer* apRenderer);
        virtual ~iLowLevelGraphics() = default;
        
        virtual bool Init(const char* asWindowTitle, tVector2l avWindowSize, bool abFullscreen) = 0;

		tVector2f GetScreenSizeFloat();
		tVector2f GetVirtualSize();
        virtual iRenderer* GetRenderer() const = 0;

        virtual iTexture* CreateTexture() const = 0;

        virtual void SetCursorVisible(bool abVisible) const = 0;

    protected:
        iRenderer* mpRenderer = nullptr;

		tVector2l mvScreenSize;
		tVector2f mvVirtualSize;
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICS_H