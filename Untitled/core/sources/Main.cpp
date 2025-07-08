#include <Game.h>

using namespace baizel;

#undef main
int main(int argc, char** argv)
{
	cGame Game;
	if (Game.Init() == false)
	{
		cLog::Error("Failed to initialize game!");
		return EXIT_FAILURE;
	}

	Game.Run();
	Game.Exit();

	return EXIT_SUCCESS;
}