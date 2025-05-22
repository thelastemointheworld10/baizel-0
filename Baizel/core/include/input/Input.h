#ifndef BAIZEL_INPUT_H
#define BAIZEL_INPUT_H

#include <SDL2/SDL.h>

#include <input/LowLevelInput.h>
#include <input/Keyboard.h>
#include <input/Mouse.h>

namespace baizel
{
    class cInput final
    {
    public:
        cInput(iLowLevelInput* apLowLevelInput);
        ~cInput();

        iLowLevelInput* GetLowLevel();

        iKeyboard* GetKeyboard();
        void SetKeyboard(iKeyboard* apKeyboard);
		iMouse* GetMouse();
		void SetMouse(iMouse* apMouse);

        void Update();

    private:
        iLowLevelInput* mpLowLevelInput;

        tInputDevicesList mlstDevices;
        iKeyboard* mpKeyboard;
        iMouse* mpMouse;
    };
}

#endif // BAIZEL_INPUT_H