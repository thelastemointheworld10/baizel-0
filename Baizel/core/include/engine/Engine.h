#ifndef BAIZEL_ENGINE_H
#define BAIZEL_ENGINE_H

#include <string>

#include <math/Math.h>
#include <math/MathTypes.h>
#include <engine/Log.h>

#include <engine/EngineSetup.h>
#include <graphics/Renderer.h>
#include <graphics/Graphics.h>
#include <input/Input.h>
#include <engine/TimeStep.h>
#include <graphics/Animation.h>
#include <graphics/Font.h>

namespace baizel
{
    class iEngineSetup;

    class cEngine final
    {
    public:
        cEngine(iEngineSetup* apEngineSetup);
        ~cEngine();

        bool Init(std::string asWindowTitle, tVector2l avWindowSize, bool abFullscreen);
        void Run();
        void Exit();
        
    private:
        bool mbRunning;

        iEngineSetup* mpEngineSetup = nullptr;
        cGraphics* mpGraphics = nullptr;
        cInput* mpInput = nullptr;
        iSystem* mpSystem = nullptr;

        cTimeStep* mpTimeStep = nullptr;
    };
}

#endif // BAIZEL_ENGINE_H