#ifndef BAIZEL_INPUT_H
#define BAIZEL_INPUT_H

#include <SDL2/SDL.h>

#include <interfaces/LowLevelInput.h>
#include <interfaces/Keyboard.h>

namespace baizel
{
    class cInput final
    {
    public:
        cInput(iLowLevelInput* apLowLevelInput);

        iKeyboard* GetKeyboard();
        void SetKeyboard(iKeyboard* apKeyboard);

        void Update();

    private:
        iLowLevelInput* mpLowLevelInput;

        tInputDevicesList mlstDevices;
        iKeyboard* mpKeyboard;
    };
}

#endif // BAIZEL_INPUT_H