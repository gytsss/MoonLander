#include <iostream>
#include <ctime>

#include "Game.h"

void runProgram();
void defaults();

int main()
{
	runProgram();
	return 0;
}

void runProgram()
{
	defaults();
	Topo::Game* game = new Topo::Game();
	game->loop();
	delete game;
}

void defaults()
{
	//system(".Init.bat");
	srand(static_cast<unsigned int>(time(nullptr)));
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	InitWindow(1280, 1000, "Moon Patrol 0.3");
	SetTargetFPS(60);
}