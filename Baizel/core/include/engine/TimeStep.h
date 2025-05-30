#ifndef BAIZEL_TIMESTEP_H
#define BAIZEL_TIMESTEP_H

#include <engine/Log.h>
#include <system/Timer.h>
#include <math/Math.h>

namespace baizel
{
    class cTimeStep final
    {
    public:
        cTimeStep(iSystem* apSystem);

        void AddFrame();

        float GetTimeStep() const;

    private:
        float mfCurrentFrameTime;
        float mfLastFrameTime;

        float mfTimeStep;

        iSystem* mpSystem;
    };
}

#endif // BAIZEL_TIMESTEP_H