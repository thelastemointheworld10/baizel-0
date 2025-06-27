#ifndef BAIZEL_TIMESTEP_H
#define BAIZEL_TIMESTEP_H

#include <engine/Log.h>
#include <system/ApplicationTime.h>
#include <math/Math.h>

namespace baizel
{
    class cTimeStep final
    {
    public:
        cTimeStep(iApplicationTime* apApplicationTime);

        void AddFrame();

        float GetTimeStep() const;

    private:
        float mfCurrentFrameTime;
        float mfLastFrameTime;

        float mfTimeStep;

        iApplicationTime* mpApplicationTime;
    };
}

#endif // BAIZEL_TIMESTEP_H