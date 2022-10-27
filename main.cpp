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
    Game* game = new Game();
    game->loop();
    delete game;
}

void defaults()
{
    srand(time(nullptr));
    InitWindow(1280, 1000, "Moon Patrol 0.1 - Topo");
    SetTargetFPS(60);
}