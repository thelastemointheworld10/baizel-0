#ifndef BAIZEL_ENGINESETUPSDL_H
#define BAIZEL_ENGINESETUPSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <diagnostics/Log.h>
#include <engine/EngineSetup.h>

#include <impl/graphics/LowLevelGraphicsSDL.h>
#include <impl/input/LowLevelInputSDL.h>
#include <impl/input/KeyboardSDL.h>
#include <impl/input/MouseSDL.h>
#include <impl/core/ApplicationTimeSDL.h>

namespace baizel
{
    class cEngineSetupSDL : public iEngineSetup
    {
    public:
		cEngineSetupSDL();
        ~cEngineSetupSDL() override;

        cGraphics* CreateGraphics() const override;
        cInput* CreateInput(cEngine* apEngine, iLowLevelGraphics* apGraphics) const override;
        iApplicationTime* CreateApplicationTime() const override;
    };
}

#endif // BAIZEL_ENGINESETUPSDL_H