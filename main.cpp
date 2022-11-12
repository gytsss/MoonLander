#include <iostream>
#include <ctime>

#include "Game.h"

void runProgram();
void defaults();

void main()
{
	runProgram();
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
	srand(time(nullptr));
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	InitWindow(1280, 1000, "Moon Patrol 0.1 - Topo");
	SetTargetFPS(60);
}