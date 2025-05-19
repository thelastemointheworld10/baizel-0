#ifndef BAIZEL_GAMESETUP_H
#define BAIZEL_GAMESETUP_H

#include <Engine.h>

#include <interfaces/LowLevelGraphics.h>
#include <interfaces/LowLevelInput.h>
#include <Input.h>

namespace baizel
{
    class cEngine;

    class iGameSetup
    {
    public:
        virtual ~iGameSetup() = default;

        virtual iLowLevelGraphics* CreateGraphics() = 0;
        virtual cInput* CreateInput() = 0;
    };
}

#endif // BAIZEL_GAMESETUP_H