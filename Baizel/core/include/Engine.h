#ifndef BAIZEL_ENGINE_H
#define BAIZEL_ENGINE_H

#include <string>
#include <SDL2/SDL.h>
#include <math/MathTypes.h>
#include <implementation/GameSetup.h>
#include <implementation/Graphics.h>
#include <implementation/LowLevelGraphicsSDL.h>
#include <implementation/LowLevelInput.h>
#include <Log.h>

namespace baizel
{
    class iGameSetup;

    class cEngine final
    {
    public:
        cEngine(iGameSetup* apGameSetup);
        ~cEngine();

        bool Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen);
        void Run();
        void Exit();
    private:
        bool mbRunning;

        iGameSetup* mpGameSetup;
        cGraphics* mpGraphics;
        iLowLevelInput* mpInput;
    };
}

#endif // BAIZEL_ENGINE_H