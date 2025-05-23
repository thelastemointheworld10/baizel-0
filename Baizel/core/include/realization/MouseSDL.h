#ifndef BAIZEL_MOUSESDL_H
#define BAIZEL_MOUSESDL_H

#include <SDL2/SDL.h>

#include <realization/LowLevelInputSDL.h>
#include <graphics/LowLevelGraphics.h>
#include <input/Mouse.h>

namespace baizel
{
	class cMouseSDL final : public iMouse
	{
	public:
		cMouseSDL(cLowLevelInputSDL* apLowLevelInputSDL, iLowLevelGraphics* apLowLevelGraphics);

		bool GetButtonPressed(eMouseButton aKey) override;

		eMouseButton SDLToButton(int alKey);

		void Update() override;

	private:
		std::vector<bool> mvButtonArray;

		cLowLevelInputSDL* mpLowLevelInputSDL;
	};
}

#endif // BAIZEL_MOUSESDL_H