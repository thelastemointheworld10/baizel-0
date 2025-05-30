#ifndef BAIZEL_FPSMANAGER_H
#define BAIZEL_FPSMANAGER_H

#include <engine/Log.h>
#include <system/Timer.h>
#include <math/Math.h>

namespace baizel
{
    class cFPSManager final
    {
    public:
        cFPSManager(iSystem* apSystem);

        void AddFrame();

        void SetFPSLimit(int alFPSLimit);
        float GetTimeStep() const;

    private:
        void LimitFPS() const;

    private:
        int mlFrames;

        int mlFPS;
        int mlFPSLimit;

        float mfCurrentFrameTime;
        float mfLastFrameTime;

        float mfFrameRate = 0.016; // 1 / 60FPS = 0.016

        float mfTimeStep;

        iSystem* mpSystem;
    };
}

#endif // BAIZEL_FPSMANAGER_H