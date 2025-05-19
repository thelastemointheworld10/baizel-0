#ifndef BAIZEL_ENGINE_H
#define BAIZEL_ENGINE_H

#include <string>

#include <math/MathTypes.h>
#include <Log.h>

#include <interfaces/GameSetup.h>
#include <interfaces/LowLevelGraphics.h>
#include <interfaces/Renderer.h>
#include <Input.h>

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

        iGameSetup* mpGameSetup = nullptr;
        iLowLevelGraphics* mpGraphics = nullptr;
        cInput* mpInput = nullptr;
    };
}

#endif // BAIZEL_ENGINE_H