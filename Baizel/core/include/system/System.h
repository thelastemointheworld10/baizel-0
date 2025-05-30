#ifndef BAIZEL_SYSTEM_H
#define BAIZEL_SYSTEM_H

#include <cstdint>

namespace baizel
{
    class iSystem
    {
    public:
        virtual int GetTimeInMilliSec() const = 0;
        virtual float GetTimeInSec() const = 0;

        virtual void SleepForMilliSec(int alTime) const = 0;
        virtual void SleepForSec(int alTime) const = 0;
    };
}

#endif // BAIZEL_SYSTEM_H

