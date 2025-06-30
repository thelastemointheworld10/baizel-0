#ifndef BAIZEL_ENGINE_H
#define BAIZEL_ENGINE_H

#include <string>

#include <math/Math.h>
#include <math/MathTypes.h>
#include <diagnostics/Log.h>

#include <engine/EngineSetup.h>
#include <graphics/Renderer.h>
#include <graphics/Graphics.h>
#include <input/Input.h>
#include <engine/TimeStep.h>
#include <core/Timer.h>
#include <graphics/Animation.h>
#include <audio/AudioSystem.h>
#include <engine/Updater.h>

namespace baizel
{
    class iEngineSetup;

    class cEngine final
    {
    public:
        cEngine(iEngineSetup* apEngineSetup, iAudioSystem* apAudioSystem);
        ~cEngine();

        bool Init(const std::string& asWindowTitle, tVector2l avWindowSize, tVector2f avVirtualSize, bool abFullscreen);
        void Run();
        void Exit();

        iAudioSystem* GetAudioSystem() const;
        cGraphics* GetGraphics() const;
        cInput* GetInput() const;
        iApplicationTime* GetApplicationTime() const;
        cUpdater* GetUpdater() const;
        
    private:
        bool mbRunning;

        iEngineSetup* mpEngineSetup = nullptr;
        iAudioSystem* mpAudioSystem = nullptr;
        cGraphics* mpGraphics = nullptr;
        cInput* mpInput = nullptr;
        iApplicationTime* mpApplicationTime = nullptr;
        cUpdater* mpUpdater = nullptr;
        cTimeStep* mpTimeStep = nullptr;
    };
}

#endif // BAIZEL_ENGINE_H