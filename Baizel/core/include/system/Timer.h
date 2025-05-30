#ifndef BAIZEL_TIMER_H
#define BAIZEL_TIMER_H

#include <cstdint>

#include <system/System.h>

namespace baizel
{
    class cTimer final
    {
    public:
        cTimer(iSystem* apSystem);

        void Start();

        float GetTimeInMilliSec();
        float GetTimeInSec();

    protected:
        uint32_t mlStartTime = 0;

        iSystem* mpSystem;
    };
}

#endif // BAIZEL_TIMER_H