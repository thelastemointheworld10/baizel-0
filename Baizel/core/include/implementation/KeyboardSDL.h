#ifndef BAIZEL_KEYBOARDSDL_H
#define BAIZEL_KEYBOARDSDL_H

#include <SDL2/SDL.h>

#include <interfaces/Keyboard.h>

namespace baizel
{
	class cKeyboardSDL final : public iKeyboard
	{
	public:
		cKeyboardSDL();

		bool GetAnyKeyPressed() override;
		bool GetKeyDown(eKey aKey) override;

		void Update() override;

	private:
		std::vector<bool> mvKeyArray;
	};
}

#endif // BAIZEL_KEYBOARDSDL_H