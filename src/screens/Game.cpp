#include "Game.h"
#include <ctime>


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
			input();

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
		map->setIsFinished(false);
	}

	void Game::update()
	{
		if (map->getIsFinished())
		{
			isPlaying = false;

			delete map;
			map = new Map();

			if (isMultiplayer)
			{
				map->setMultiplayer(isMultiplayer);
			}

		}
		else
		{

			map->update(scenes);
		}

	}

	void Game::draw()
	{
		int titleLenght = MeasureText("Minimalist Patrol", static_cast <int>(10 * map->getUnit()));
		int creditsLenght = MeasureText("Topo Fabbri and Godoy Tobias", static_cast <int>(5 * map->getUnit()));
		int playLenght = MeasureText("Play", static_cast <int>(5 * map->getUnit()));
		int creditLenght = MeasureText("Credits", static_cast <int>(5 * map->getUnit()));
		int exitLenght = MeasureText("Exit", static_cast <int>(5 * map->getUnit()));
		int multiplayerLenght = MeasureText("Multiplayer", static_cast <int>(5 * map->getUnit()));



		switch (scenes)
		{
		case Scenes::Exit:  break;

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



			DrawText("Minimalist patrol", GetScreenWidth() / 2 - titleLenght / 2, static_cast<int>(GetScreenHeight() / 5.5), static_cast <int>(10 * map->getUnit()), RED);
			DrawCircleLines(GetScreenWidth() / 2, GetScreenHeight() / 2, 15 * map->getUnit(), RED);
			DrawCircleLines(GetScreenWidth() / 2, static_cast<int>(GetScreenHeight() / 1.3), 15 * map->getUnit(), BLUE);
			DrawCircleLines(static_cast<int>(GetScreenWidth() / 3), static_cast<int>(GetScreenHeight() / 1.57), 15 * map->getUnit(), ORANGE);
			DrawCircleLines(static_cast<int>(GetScreenWidth() / 1.5), static_cast<int>(GetScreenHeight() / 1.57), 15 * map->getUnit(), GREEN);

			DrawText("Play", GetScreenWidth() / 2 - playLenght / 2, static_cast<int>(GetScreenHeight() / 2.1), static_cast <int>(5 * map->getUnit()), RED);
			DrawText("Credits", GetScreenWidth() / 2 - creditLenght / 2, static_cast<int>(GetScreenHeight() / 1.35), static_cast <int>(5 * map->getUnit()), BLUE);
			DrawText("Exit", GetScreenWidth() / 3 - exitLenght / 2, static_cast<int>(GetScreenHeight() / 1.62), static_cast <int>(5 * map->getUnit()), ORANGE);
			DrawText("Multiplayer", static_cast<int>(GetScreenWidth() / 1.5 - multiplayerLenght / 2), static_cast<int>(GetScreenHeight() / 1.62), static_cast <int>(5 * map->getUnit()), GREEN);

			EndDrawing();
			break;

		case Scenes::Credits:
			BeginDrawing();
			ClearBackground(BLACK);

			DrawText("Topo Fabbri and Godoy Tobias", GetScreenWidth() / 2 - creditsLenght / 2, GetScreenHeight() / 2, static_cast <int>(5 * map->getUnit()), RED);
			DrawText("<- (Space)", 10, static_cast<int>(GetScreenHeight() / 1.1), static_cast <int>(5 * map->getUnit()), RED);


			EndDrawing();
			break;

		default:;
		}

		if (WindowShouldClose())
			scenes = Scenes::Exit;




	}

	void Game::input()
	{
		if (scenes == Scenes::MainMenu && CheckCollisionPointCircle(GetMousePosition(), Vector2{ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) }, 15 * map->getUnit()) &&
			IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			scenes = Scenes::Play;
			isMultiplayer = false;
		}
		else if (scenes == Scenes::MainMenu && CheckCollisionPointCircle(GetMousePosition(), Vector2{ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 1.3) }, 15 * map->getUnit()) &&
			IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			scenes = Scenes::Credits;
		else if (scenes == Scenes::MainMenu && CheckCollisionPointCircle(GetMousePosition(), Vector2{ static_cast<float>(GetScreenWidth() / 3), static_cast<float>(GetScreenHeight() / 1.57) }, 15 * map->getUnit()) &&
			IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			scenes = Scenes::Exit;
		else if (scenes == Scenes::MainMenu && CheckCollisionPointCircle(GetMousePosition(), Vector2{ static_cast<float>(GetScreenWidth() / 1.5), static_cast<float>(GetScreenHeight() / 1.57) }, 15 * map->getUnit()) &&
			IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			map->setMultiplayer(true);
			scenes = Scenes::Play;
			isMultiplayer = true;
		}
		else if (scenes == Scenes::Credits && IsKeyPressed(KEY_SPACE))
			scenes = Scenes::MainMenu;
	}

	void Game::credits()
	{
		draw();
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
		srand(static_cast<unsigned int>(time(nullptr)));
		SetWindowState(FLAG_WINDOW_RESIZABLE);
		InitWindow(1280, 1000, "Minimalist Patrol 1.1");
		SetTargetFPS(60);
	}
}