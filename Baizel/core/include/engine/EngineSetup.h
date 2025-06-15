#ifndef BAIZEL_ENGINESETUP_H
#define BAIZEL_ENGINESETUP_H

#include <engine/Engine.h>

#include <graphics/Graphics.h>
#include <input/Input.h>
#include <time/ApplicationTime.h>

namespace baizel
{
    class cEngine;

    class iEngineSetup
    {
    public:
        virtual ~iEngineSetup() = default;

        virtual cGraphics* CreateGraphics() const = 0;
        virtual cInput* CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics) const = 0;
        virtual iApplicationTime* CreateApplicationTime() const = 0;
    };
}

#endif // BAIZEL_ENGINESETUP_H