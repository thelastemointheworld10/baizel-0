#ifndef PLAYER_H
#define PLAYER_H

#include <implementation/Graphics.h>

class cPlayer final
{
public:
	cPlayer(cGraphics* apGraphics);

	bool Init();
	void Update();

private:
	cGraphics* mpGraphics;

	SDL_Texture* mpTexture;
};

#endif