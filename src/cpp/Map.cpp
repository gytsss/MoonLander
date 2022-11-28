#include "Map.h"

namespace Topo
{
	Map::Map()
	{
		const float screenWidth = static_cast<float>(GetScreenWidth());
		const float screenHeight = static_cast<float>(GetScreenHeight());

		unit = screenWidth / 160;

		map.width = screenWidth;
		map.height = 90 * unit;
		map.x = 0;
		map.y = screenHeight / 2 - map.height / 2;

		isFinished = false;
		isMultiplayer = false;
		isRunning = false;

		tint = { 185, 235, 255,255 };


		player = new Character(unit, map);
		secondPlayer = new Character(unit, map);
		obs = new Obstacle(unit, map);
		flyEnemy = new FlyEnemy(unit, map);
		bg = new Background(map);
		clouds = new Clouds(map);
	}

	Map::~Map()
	{
		delete player;
		delete secondPlayer;
		delete obs;
		delete flyEnemy;
	}

	Vector2 Map::getSize()
	{
		return { map.width, map.height };
	}

	float Map::getPosY()
	{
		return map.y;
	}

	float Map::getHeight()
	{
		return map.height;
	}

	float Map::getWidth()
	{
		return map.width;
	}

	float Map::getUnit()
	{
		return unit;
	}

	bool Map::getIsFinished()
	{
		return isFinished;
	}

	bool Map::getIsRunning()
	{
		return isRunning;
	}

	bool Map::getmulti()
	{
		return isMultiplayer;
	}

	void Map::update(Scenes& activeScene)
	{
		const float screenWidth = static_cast<float>(GetScreenWidth());
		const float screenHeight = static_cast<float>(GetScreenHeight());

		unit = screenWidth / 160;

		float playerYDif = player->getY();

		map.width = screenWidth;
		map.height = 90 * unit;
		map.x = 0;
		map.y = screenHeight / 2 - map.height / 2;

		if (isMultiplayer)
		{
			player->setDestX(secondPlayer->getDest().x - 15 * unit);
			secondPlayer->setColor(BLACK);
		}

		if (IsKeyPressed(KEY_SPACE))
			isRunning = !isRunning;


		if (player->getIsAlive() && secondPlayer->getIsAlive())
		{

			if (isRunning)
			{
				if (activeScene == Scenes::Play)
				{
					input();
				}

				checkCollisions();

				player->update(unit, map);

				if (isMultiplayer)
					secondPlayer->update(unit, map);

				obs->update(unit, map);
				flyEnemy->update(unit);
				bg->update(unit, map);
				clouds->update(unit, map);


				playerYDif = player->getY() - playerYDif;

				obs->updateParallax(playerYDif);
				bg->updateParallax(playerYDif);
				clouds->updateParallax(playerYDif);
				flyEnemy->updateParallax(playerYDif);

				if (obs->isBehindPlayer())
				{
					delete obs;
					obs = new Obstacle(unit, map);
					player->increaseScore(1);
				}

				if (flyEnemy->getPos().x > screenWidth)
				{
					delete flyEnemy;
					flyEnemy = new FlyEnemy(unit, map);
				}
			}
			else
			{
				if (IsKeyPressed(KEY_ENTER))
				{
					isFinished = true;
					activeScene = Scenes::MainMenu;


				}
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				isFinished = true;
				activeScene = Scenes::MainMenu;

			}
		}
	}


	void Map::draw()
	{
		int scoreLength = MeasureText(TextFormat("&i", player->getScore()), static_cast<int>(50 * unit));
		int backMenuLength = MeasureText("Back to menu (Enter)", static_cast<int>(8 * unit));
		int howTPLength = MeasureText("Left click to shoot - W to jump", static_cast<int>(5 * unit));
		int howTPLength2 = MeasureText("P2: K to shoot - J to jump (Black)", static_cast<int>(5 * unit));
		int enterLength = MeasureText("Space to play", static_cast<int>(8 * unit));

		if (player->getIsAlive() && secondPlayer->getIsAlive())
		{
			DrawRectangleRec(map, tint);

			DrawText(TextFormat("%i", player->getScore()), GetScreenWidth() / 2 - scoreLength / 2, static_cast<int>(GetScreenHeight() / 5), static_cast<int>(50 * unit), player->getScoreTint());

			clouds->draw();
			bg->draw();
			player->draw();

			if (isMultiplayer)
				secondPlayer->draw();

			obs->draw();
			flyEnemy->draw();

			if (!isRunning)
			{
				if (isMultiplayer)
				{
					DrawText("P1: Left click to shoot - W to jump", GetScreenWidth() / 2 - howTPLength / 2, static_cast<int>(GetScreenHeight() / 6.5), static_cast<int>(5 * unit), BLACK);
					DrawText("P2: K to shoot - Key up to jump (Black)", GetScreenWidth() / 2 - howTPLength2 / 2, static_cast<int>(GetScreenHeight() / 5), static_cast<int>(5 * unit), BLACK);
				}
				else
				{
					DrawText("Left click to shoot - W to jump", GetScreenWidth() / 2 - howTPLength / 2, static_cast<int>(GetScreenHeight() / 6.5), static_cast<int>(5 * unit), BLACK);
				}

				DrawText("Space to play", GetScreenWidth() / 2 - enterLength / 2, static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(8 * unit), BLACK);
				DrawText("Back to menu (Enter)", GetScreenWidth() / 2 - backMenuLength / 2, static_cast<int>(GetScreenHeight() / 1.3), static_cast<int>(8 * unit), BLACK);

			}
		}
		else
		{
			DrawRectangleRec(map, tint);

			clouds->draw();
			bg->draw();

			DrawText(TextFormat("%i", player->getScore()), GetScreenWidth() / 2 - scoreLength / 2, static_cast<int>(GetScreenHeight() / 5), static_cast<int>(50 * unit), player->getScoreTint());

			DrawText("Back to menu (Enter)", GetScreenWidth() / 2 - backMenuLength / 2, static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(8 * unit), BLACK);

		}


	}

	void Map::input()
	{
		if (IsKeyPressed(KEY_W))
			player->jump(unit);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			player->shoot();

		if (isMultiplayer)
		{
			if (IsKeyPressed(KEY_UP))
				secondPlayer->jump(unit);

			if (IsKeyPressed(KEY_K))
				secondPlayer->shoot();
		}

	}

	void Map::checkCollisions()
	{
		if (rectanglesCollide(player->getDest(), obs->getCol()))
			player->setAlive(false);

		if (isMultiplayer)
		{
			if (rectanglesCollide(secondPlayer->getDest(), obs->getCol()))
				secondPlayer->setAlive(false);
		}

		for (int i = 0; i < maxBullets; i++)
		{
			if (CheckCollisionCircleRec(player->getBullet(i)->getPos(), static_cast<float>(player->getBullet(i)->getRadius()), Rectangle{ flyEnemy->getPos().x, flyEnemy->getPos().y, flyEnemy->getSize().x, flyEnemy->getSize().y }))
			{
				player->getBullet(i)->setActive(false, player->getX(), player->getY());
				flyEnemy->restart();
				player->increaseScore(1);
			}

			if (isMultiplayer)
			{
				if (CheckCollisionCircleRec(secondPlayer->getBullet(i)->getPos(), static_cast<float>(secondPlayer->getBullet(i)->getRadius()), Rectangle{ flyEnemy->getPos().x, flyEnemy->getPos().y, flyEnemy->getSize().x, flyEnemy->getSize().y }))
				{
					secondPlayer->getBullet(i)->setActive(false, player->getX(), player->getY());
					flyEnemy->restart();
					player->increaseScore(1);
				}
			}

		}


	}
	void Map::setMultiplayer(bool areTwoPlayers)
	{
		isMultiplayer = areTwoPlayers;
	}
	void Map::setIsFinished(bool finish)
	{
		isFinished = finish;
	}
}