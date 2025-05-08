#ifndef BAIZEL_GAMESETUP_H
#define BAIZEL_GAMESETUP_H

#include <Engine.h>
#include <implementation/LowLevelGraphics.h>
#include <implementation/LowLevelInput.h>

namespace baizel
{
    class cEngine;

    class iGameSetup
    {
    public:
        virtual ~iGameSetup() = default;

        virtual iLowLevelGraphics* CreateGraphics() = 0;
        virtual iLowLevelInput* CreateInput(cEngine* apEngine) = 0;
    };
}

#endif // BAIZEL_GAMESETUP_H