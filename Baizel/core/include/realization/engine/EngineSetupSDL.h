#ifndef BAIZEL_ENGINESETUPSDL_H
#define BAIZEL_ENGINESETUPSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/Log.h>
#include <engine/EngineSetup.h>

#include <realization/graphics/LowLevelGraphicsSDL.h>
#include <realization/input/LowLevelInputSDL.h>
#include <realization/input/KeyboardSDL.h>
#include <realization/input/MouseSDL.h>

namespace baizel
{
    class cEngineSetupSDL : public iEngineSetup
    {
    public:
		cEngineSetupSDL();
        ~cEngineSetupSDL() override;

        cGraphics* CreateGraphics() override;
        cInput* CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics) override;
    };
}

#endif // BAIZEL_ENGINESETUPSDL_H