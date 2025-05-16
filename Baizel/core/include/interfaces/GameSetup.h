#ifndef BAIZEL_GAMESETUP_H
#define BAIZEL_GAMESETUP_H

#include <Engine.h>
#include <interfaces/LowLevelGraphics.h>
#include <interfaces/LowLevelInput.h>

namespace baizel
{
    class cEngine;
    class cGraphics;

    class iGameSetup
    {
    public:
        virtual ~iGameSetup() = default;

        virtual cGraphics* CreateGraphics() = 0;
        virtual iLowLevelInput* CreateInput(cEngine* apEngine) = 0;
    };
}

#endif // BAIZEL_GAMESETUP_H