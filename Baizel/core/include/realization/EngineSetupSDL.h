#ifndef BAIZEL_ENGINESETUPSDL_H
#define BAIZEL_ENGINESETUPSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/Log.h>
#include <engine/EngineSetup.h>

#include <realization/LowLevelGraphicsSDL.h>
#include <realization/LowLevelInputSDL.h>
#include <realization/KeyboardSDL.h>
#include <realization/MouseSDL.h>

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