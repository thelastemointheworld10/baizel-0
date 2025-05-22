#ifndef BAIZEL_LOWLEVELINPUT_H
#define BAIZEL_LOWLEVELINPUT_H

#include <input/InputTypes.h>

namespace baizel
{
    class iLowLevelInput
    {
    public:
        virtual void PollEvents() = 0;
        virtual void ClearEvents() = 0;
    };
}

#endif // BAIZEL_LOWLEVELINPUT_H