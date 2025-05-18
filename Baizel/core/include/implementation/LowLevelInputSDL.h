#ifndef BAIZEL_LOWLEVELINPUTSDL_H
#define BAIZEL_LOWLEVELINPUTSDL_H

#include <Engine.h>

#include <interfaces/LowLevelInput.h>

namespace baizel
{
    class cLowLevelInputSDL : public iLowLevelInput
    {
    public:
        cLowLevelInputSDL(cEngine* apEngine);
        ~cLowLevelInputSDL() override;

        void Update() override;

    private:
        void UpdateEvents() override;
        void UpdateKeyboard() override;
        void UpdateMouse() override;
        void UpdateJoystick() override;

    private:
        cEngine* mpEngine;
        SDL_Event mEvent;
    };
}

#endif // BAIZEL_LOWLEVELINPUTSDL_H
