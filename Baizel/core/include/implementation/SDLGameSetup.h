#ifndef BAIZEL_SDLGAMESETUP_H
#define BAIZEL_SDLGAMESETUP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <interfaces/GameSetup.h>
#include <implementation/LowLevelGraphicsSDL.h>
#include <implementation/LowLevelInputSDL.h>
#include <Log.h>

namespace baizel
{
    class cSDLGameSetup : public iGameSetup
    {
    public:
        cSDLGameSetup();
        ~cSDLGameSetup() override;

        cGraphics* CreateGraphics() override;
        iLowLevelInput* CreateInput(cEngine* apEngine) override;
    };
}

#endif // BAIZEL_SDLGAMESETUP_H