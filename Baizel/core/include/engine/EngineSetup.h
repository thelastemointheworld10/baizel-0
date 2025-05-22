#ifndef BAIZEL_GAMESETUP_H
#define BAIZEL_GAMESETUP_H

#include <engine/Engine.h>

#include <graphics/Graphics.h>
#include <input/Input.h>

namespace baizel
{
    class cEngine;

    class iEngineSetup
    {
    public:
        virtual ~iEngineSetup() = default;

        virtual cGraphics* CreateGraphics() = 0;
        virtual cInput* CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics) = 0;
    };
}

#endif // BAIZEL_GAMESETUP_H