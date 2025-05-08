#ifndef BAIZEL_LOWLEVELINPUT_H
#define BAIZEL_LOWLEVELINPUT_H

#include <SDL2/SDL.h>
#include <Log.h>

namespace baizel
{
    class iLowLevelInput
    {
    public:
        virtual ~iLowLevelInput() = default;

        virtual void Update() = 0;
    private:
        virtual void UpdateEvents() = 0;
        virtual void UpdateKeyboard() = 0;
        virtual void UpdateMouse() = 0;
        virtual void UpdateJoystick() = 0;
    };
}

#endif // BAIZEL_LOWLEVELINPUT_H
