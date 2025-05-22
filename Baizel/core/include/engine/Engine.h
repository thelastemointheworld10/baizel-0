#ifndef BAIZEL_ENGINE_H
#define BAIZEL_ENGINE_H

#include <string>

#include <math/MathTypes.h>
#include <engine/Log.h>

#include <engine/EngineSetup.h>
#include <graphics/LowLevelGraphics.h>
#include <graphics/Renderer.h>
#include <input/Input.h>

namespace baizel
{
    class iEngineSetup;

    class cEngine final
    {
    public:
        cEngine(iEngineSetup* apGameSetup);
        ~cEngine();

        bool Init(const char* asWindowTitle, cVector2l avWindowSize, bool abFullscreen);
        void Run();
        void Exit();
    private:
        bool mbRunning;

        iEngineSetup* mpGameSetup = nullptr;
        iLowLevelGraphics* mpGraphics = nullptr;
        cInput* mpInput = nullptr;
    };
}

#endif // BAIZEL_ENGINE_H