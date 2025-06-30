#ifndef BAIZEL_APPLICATIONTIMESDL_H
#define BAIZEL_APPLICATIONTIMESDL_H

#include <SDL2/SDL.h>

#include <core/ApplicationTime.h>

namespace baizel
{
    class cApplicationTimeSDL final : public iApplicationTime
    {
    public:
        int GetTimeInMilliSec() const override;
        float GetTimeInSec() const override;

        void SleepForMilliSec(int alTime) const override;
        void SleepForSec(int alTime) const override;
    };
}

#endif // BAIZEL_APPLICATIONTIMESDL_H