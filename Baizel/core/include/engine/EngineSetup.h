#ifndef BAIZEL_GAMESETUP_H
#define BAIZEL_GAMESETUP_H

#include <engine/Engine.h>

#include <graphics/LowLevelGraphics.h>
#include <input/LowLevelInput.h>
#include <input/Input.h>

namespace baizel
{
    class cEngine;

    class iEngineSetup
    {
    public:
        virtual ~iEngineSetup() = default;

        virtual iLowLevelGraphics* CreateGraphics() = 0;
        virtual cInput* CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics) = 0;
    };
}

#endif // BAIZEL_GAMESETUP_H