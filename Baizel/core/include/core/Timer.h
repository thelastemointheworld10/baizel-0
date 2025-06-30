#ifndef BAIZEL_TIMER_H
#define BAIZEL_TIMER_H

#include <cstdint>

#include <diagnostics/Log.h>

#include <core/ApplicationTime.h>

namespace baizel
{
    class cTimer final
    {
    public:
        cTimer(iApplicationTime* apApplicationTime);

        void Start();
        void Stop();
        void Pause();
        void Unpause();

        float GetTimeInMilliSec() const;
        float GetTimeInSec() const;

        bool IsStarted() const;
        bool IsPaused() const;

    protected:
        uint32_t mlStartTicks = 0;
        uint32_t mlPausedTicks = 0;

        bool mbStarted = false;
        bool mbPaused = false;

        iApplicationTime* mpApplicationTime;
    };
}

#endif // BAIZEL_TIMER_H