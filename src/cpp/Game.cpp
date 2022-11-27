#include "Game.h"

namespace Topo
{
	Game::Game()
	{
		isPlaying = false;
		scenes = Scenes::MainMenu;
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
			if (scenes == Scenes::MainMenu && CheckCollisionPointCircle(GetMousePosition(), Vector2{ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) }, 15 * map->getUnit()) &&
				IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				scenes = Scenes::Play;
			else if (scenes == Scenes::MainMenu && CheckCollisionPointCircle(GetMousePosition(), Vector2{ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 1.3) }, 15 * map->getUnit()) &&
				IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
				scenes = Scenes::Credits;
			else if (scenes == Scenes::Credits && IsKeyPressed(KEY_BACKSPACE))
				scenes = Scenes::MainMenu;

			switch (scenes)
			{
			case Scenes::Exit: break;

			case Scenes::Play:
				play();
				break;

			case Scenes::MainMenu:
				menu();
				break;

			case Scenes::Credits:
				credits();
				break;

			default:;
			}

			if (WindowShouldClose())
				scenes = Scenes::Exit;

		} while (scenes != Scenes::Exit);
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
		if (map->getIsFinished())
		{
			isPlaying = false;
			if (IsKeyPressed(KEY_SPACE))
			{
				scenes = Scenes::MainMenu;

				delete map;
				map = new Map();
			}
		}
		else
		{
			map->update(scenes);
		}

	}

	void Game::draw()
	{
		float titleLenght = static_cast<float>(MeasureText("Moon Patrol", 50));

		switch (scenes)
		{
		case Scenes::Exit:

			break;

		case Scenes::Play:
			BeginDrawing();
			ClearBackground(BLACK);

			map->draw();

			DrawRectangle(0, 0, GetScreenWidth(), static_cast<int>(map->getPosY()), BLACK);
			DrawRectangle(0, static_cast<int>(map->getPosY() + map->getHeight()), GetScreenWidth(), static_cast<int>(map->getPosY()), BLACK);



			DrawFPS(5, 5);
			EndDrawing();
			break;

		case Scenes::MainMenu:
			BeginDrawing();
			ClearBackground(BLACK);



			DrawText("Moon patrol", static_cast<int>(GetScreenWidth() / 2 - titleLenght / 2), GetScreenHeight() / 4, 50, RED);
			DrawCircleLines(GetScreenWidth() / 2, GetScreenHeight() / 2, 15 * map->getUnit(), RED);
			DrawCircleLines(GetScreenWidth() / 2, static_cast<int>(GetScreenHeight() / 1.3), 15 * map->getUnit(), BLUE);

			EndDrawing();
			break;

		case Scenes::Credits:
			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("Topo Fabbri and", GetScreenWidth() / 2 - 80, GetScreenHeight() / 2, static_cast <int>(5 * map->getUnit()), RED);
			DrawText("Godoy Tobias", GetScreenWidth() / 2 - 80, 600, static_cast <int>(5 * map->getUnit()), RED);

			EndDrawing();
			break;

		default:;
		}

		if (WindowShouldClose())
			scenes = Scenes::Exit;




	}

	void Game::credits()
	{
		draw();
	}
}

