#ifndef BAIZEL_LOWLEVELINPUTSDL_H
#define BAIZEL_LOWLEVELINPUTSDL_H

#include <Engine.h>
#include <implementation/LowLevelInput.h>

namespace baizel
{
    class cLowLevelInputSDL : public iLowLevelInput
    {
    public:
        cLowLevelInputSDL(cEngine* apEngine);
        ~cLowLevelInputSDL() override;

        void Update() override;
    private:
        SDL_Event mEvent;

        void UpdateEvents() override;
        void UpdateKeyboard() override;
        void UpdateMouse() override;
        void UpdateJoystick() override;

        cEngine* mpEngine;
    };
}

#endif // BAIZEL_LOWLEVELINPUTSDL_H
