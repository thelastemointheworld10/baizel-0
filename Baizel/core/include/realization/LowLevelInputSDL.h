#ifndef BAIZEL_LOWLEVELINPUTSDL_H
#define BAIZEL_LOWLEVELINPUTSDL_H

#include <SDL2/SDL.h>

#include <engine/Engine.h>

#include <input/LowLevelInput.h>
#include <graphics/LowLevelGraphics.h>

namespace baizel
{
    class cLowLevelInputSDL final : public iLowLevelInput
    {
    public:
		cLowLevelInputSDL(cEngine* apEngine, iLowLevelGraphics* apGraphics);

        void UpdateInput() override;

	private:
		cEngine* mpEngine;
		iLowLevelGraphics* mpGraphics;
    };
}

#endif // BAIZEL_LOWLEVELINPUTSDL_H