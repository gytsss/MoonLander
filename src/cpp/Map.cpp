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

		tint = { 185, 235, 255,255 };


		player = new Character(unit, map);
		obs = new Obstacle(unit, map);
		flyEnemy = new FlyEnemy(unit, map);
		bg = new Background(map);
		clouds = new Clouds(map);
	}

	Map::~Map()
	{
		delete player;
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

	void Map::update(Scenes activeScene)
	{
		const float screenWidth = static_cast<float>(GetScreenWidth());
		const float screenHeight = static_cast<float>(GetScreenHeight());

		unit = screenWidth / 160;

		float playerYDif = player->getY();

		map.width = screenWidth;
		map.height = 90 * unit;
		map.x = 0;
		map.y = screenHeight / 2 - map.height / 2;

		if (player->getIsAlive())
		{

			if (activeScene == Scenes::Play)
			{
				input();
			}

			checkCollisions();

			player->update(unit, map);
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
			isFinished = true;
		}
	}


	void Map::draw()
	{
		int scoreLength = MeasureText(TextFormat("&i", player->getScore()), static_cast<int>(50 * unit));
		int backMenuLength = MeasureText("Back to menu (SPACE)", static_cast<int>(5 * unit));

		if (player->getIsAlive())
		{
			DrawRectangleRec(map, tint);

			DrawText(TextFormat("%i", player->getScore()), GetScreenWidth() / 2 - scoreLength / 2, static_cast<int>(GetScreenHeight() / 5), static_cast<int>(50 * unit), player->getScoreTint());

			clouds->draw();
			bg->draw();
			player->draw();
			obs->draw();
			flyEnemy->draw();
		}
		else
		{
			DrawRectangleRec(map, tint);

			clouds->draw();
			bg->draw();

			DrawText(TextFormat("%i", player->getScore()), GetScreenWidth() / 2 - scoreLength / 2, static_cast<int>(GetScreenHeight() / 5), static_cast<int>(50 * unit), player->getScoreTint());

			DrawText("Back to menu (SPACE)", GetScreenWidth() / 2 - backMenuLength / 2, static_cast<int>(GetScreenHeight() / 1.5), static_cast<int>(5 * unit), RED);

			
		}

		


	}

	void Map::input()
	{
		if (IsKeyPressed(KEY_SPACE))
			player->jump(unit);


		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			player->shoot();

	}

	void Map::checkCollisions()
	{
		if (rectanglesCollide(player->getDest(), obs->getCol()))
			player->setAlive(false);

		for (int i = 0; i < maxBullets; i++)
		{
			if (CheckCollisionCircleRec(player->getBullet(i)->getPos(), static_cast<float>(player->getBullet(i)->getRadius()), Rectangle{ flyEnemy->getPos().x, flyEnemy->getPos().y, flyEnemy->getSize().x, flyEnemy->getSize().y }))
			{
				player->getBullet(i)->setActive(false, player->getX(), player->getY());
				flyEnemy->restart();
				player->increaseScore(3);
			}

		}


	}
}