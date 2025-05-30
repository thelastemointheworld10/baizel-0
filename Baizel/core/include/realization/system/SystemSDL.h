#ifndef BAIZEL_SYSTEMSDL_H
#define BAIZEL_SYSTEMSDL_H

#include <SDL2/SDL.h>

#include <system/System.h>

namespace baizel
{
    class cSystemSDL final : public iSystem
    {
    public:
        int GetTimeInMilliSec() const override;
        float GetTimeInSec() const override;

        void SleepForMilliSec(int alTime) const override;
        void SleepForSec(int alTime) const override;
    };
}

#endif // BAIZEL_SYSTEMSDL_H