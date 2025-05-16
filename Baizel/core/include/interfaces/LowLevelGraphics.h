#ifndef BAIZEL_LOWLEVELGRAPHICS_H
#define BAIZEL_LOWLEVELGRAPHICS_H

#include <string>
#include <math/MathTypes.h>

namespace baizel
{
    class iLowLevelGraphics
    {
    public:
        virtual ~iLowLevelGraphics() = default;
        
        virtual bool Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen) = 0;

        virtual void SetCursorVisible(bool abVisible) = 0;
    };
}

#endif // BAIZEL_LOWLEVELGRAPHICS_H