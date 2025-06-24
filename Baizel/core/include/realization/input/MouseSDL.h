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

		void Update() override;

		void SetCursorVisible(bool abVisible) const override;
		void SetMouseMode(eMouseMode aMouseMode) const override;

	private:
		eMouseButton SDLToButton(int alKey) const;

	private:
		cLowLevelInputSDL* mpLowLevelInputSDL;
		std::vector<bool> mvButtonArray;
	};
}

#endif // BAIZEL_MOUSESDL_H