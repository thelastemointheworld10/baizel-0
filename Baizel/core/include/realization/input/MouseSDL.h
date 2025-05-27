#ifndef BAIZEL_MOUSESDL_H
#define BAIZEL_MOUSESDL_H

#include <SDL2/SDL.h>

#include <realization/input/LowLevelInputSDL.h>
#include <graphics/LowLevelGraphics.h>
#include <input/Mouse.h>

namespace baizel
{
	class cMouseSDL final : public iMouse
	{
	public:
		cMouseSDL(cLowLevelInputSDL* apLowLevelInputSDL, iLowLevelGraphics* apLowLevelGraphics);

		bool GetButtonPressed(eMouseButton aKey) const override;

		eMouseButton SDLToButton(int alKey) const;

		void Update() override;

	private:
		std::vector<bool> mvButtonArray;

		cLowLevelInputSDL* mpLowLevelInputSDL;
	};
}

#endif // BAIZEL_MOUSESDL_H