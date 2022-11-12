#include "Game.h"

namespace Topo
{
	Game::Game()
	{
		isPlaying = false;
		scenes = MainMenu;
		map = new Map();
	}

	Game::~Game()
	{
		delete map;
	}

	void Game::loop()
	{
		do
		{
			switch (scenes)
			{
			case Exit: break;

			case Play:
				play();
				break;

			case MainMenu:
				scenes = Play;
				break;

			case Credits: break;

			default:;
			}

			if (WindowShouldClose())
				scenes = Exit;

		} while (scenes != Exit);
	}

	void Game::play()
	{
		// Begin
		if (!isPlaying)
			begin();

		// Update
		update();

		// Draw
		draw();
	}

	void Game::begin()
	{
		isPlaying = true;
	}

	void Game::update()
	{
		map->update();
	}

	void Game::draw()
	{
		BeginDrawing();

		ClearBackground(BLACK);

		map->draw();

		DrawRectangle(0, 0, GetScreenWidth(), static_cast<int>(map->getPosY()), BLACK);
		DrawRectangle(0, static_cast<int>(map->getPosY() + map->getHeight()),
			GetScreenWidth(), static_cast<int>(map->getPosY()), BLACK);

		DrawFPS(5, 5);

		EndDrawing();
	}
}