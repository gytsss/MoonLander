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
			if (scenes == MainMenu && IsKeyPressed(KEY_E))
				scenes = Play;
			else if (scenes == MainMenu && IsKeyPressed(KEY_C))
				scenes = Credits;
			else if (scenes == Credits && IsKeyPressed(KEY_BACKSPACE))
				scenes = MainMenu;

			switch (scenes)
			{
			case Exit: break;

			case Play:
				play();
				break;

			case MainMenu:
				menu();
				break;

			case Credits:
				credits();
				break;

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

	void Game::menu()
	{
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
		
			switch (scenes)
			{
			case Exit:
				
				break;

			case Play:
				BeginDrawing();
				ClearBackground(BLACK);

				map->draw();

				DrawRectangle(0, 0, GetScreenWidth(), static_cast<int>(map->getPosY()), BLACK);
				DrawRectangle(0, static_cast<int>(map->getPosY() + map->getHeight()),
					GetScreenWidth(), static_cast<int>(map->getPosY()), BLACK);

				DrawFPS(5, 5); 
				EndDrawing();
				break;

			case MainMenu:
				BeginDrawing();
				ClearBackground(BLACK);

				DrawText("Press E to start...", GetScreenWidth() / 2  - 80, GetScreenHeight() / 2, 50, RED);
				DrawText("Press C to see credits...", GetScreenWidth() / 2 - 80, 600, 50, RED);

				EndDrawing();
				break;

			case Credits:
				BeginDrawing();
				ClearBackground(BLACK);

				DrawText("Topo Fabbri and", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2, 50, RED);
				DrawText("Godoy Tobias", GetScreenWidth() / 2 - 80, 600, 50, RED);

				EndDrawing();
				break;

			default:;
			}

			if (WindowShouldClose())
				scenes = Exit;

		

		
	}

	void Game::credits()
	{
		draw();
	}
}

