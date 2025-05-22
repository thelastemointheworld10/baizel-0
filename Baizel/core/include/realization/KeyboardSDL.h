#ifndef BAIZEL_KEYBOARDSDL_H
#define BAIZEL_KEYBOARDSDL_H

#include <SDL2/SDL.h>

#include <realization/LowLevelInputSDL.h>
#include <input/Keyboard.h>

namespace baizel
{
	class cKeyboardSDL final : public iKeyboard
	{
	public:
		cKeyboardSDL(cLowLevelInputSDL* apLowLevelInputSDL);

		bool GetAnyKeyPressed() override;
		bool GetKeyPressed(eKey aKey) override;

		eKey SDLToKey(int alKey);

		void Update() override;

	private:
		std::vector<bool> mvKeyArray;

		cLowLevelInputSDL* mpLowLevelInputSDL;
	};
}

#endif // BAIZEL_KEYBOARDSDL_H