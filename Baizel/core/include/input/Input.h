#ifndef BAIZEL_INPUT_H
#define BAIZEL_INPUT_H

#include <SDL2/SDL.h>

#include <input/LowLevelInput.h>
#include <input/Keyboard.h>

namespace baizel
{
    class cInput final
    {
    public:
        cInput(iLowLevelInput* apLowLevelInput);
        ~cInput();

        iKeyboard* GetKeyboard();
        void SetKeyboard(iKeyboard* apKeyboard);
        iLowLevelInput* GetLowLevel();

        void Update();

    private:
        iLowLevelInput* mpLowLevelInput;

        tInputDevicesList mlstDevices;
        iKeyboard* mpKeyboard;
    };
}

#endif // BAIZEL_INPUT_H