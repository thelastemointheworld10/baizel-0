#ifndef BAIZEL_LOWLEVELINPUTSDL_H
#define BAIZEL_LOWLEVELINPUTSDL_H

#include <SDL2/SDL.h>

#include <interfaces/LowLevelInput.h>

namespace baizel
{
    class cLowLevelInputSDL final : public iLowLevelInput
    {
    public:
        void UpdateInput() override;
    };
}

#endif // BAIZEL_LOWLEVELINPUTSDL_H