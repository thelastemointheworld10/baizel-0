#ifndef BAIZEL_APPLICATIONTIME_H
#define BAIZEL_APPLICATIONTIME_H

namespace baizel
{
    class iApplicationTime
    {
    public:
        virtual int GetTimeInMilliSec() const = 0;
        virtual float GetTimeInSec() const = 0;

        virtual void SleepForMilliSec(int alTime) const = 0;
        virtual void SleepForSec(int alTime) const = 0;
    };
}

#endif // BAIZEL_APPLICATIONTIME_H

