#include "Game.h"

int main(int argc, char* argv[])
{
	srand(timeGetTime());
	Game game;
	game.menu();

	system("pause");

	return 0;
}
