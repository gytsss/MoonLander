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
		}

		if (flyEnemy->getPos().x > GetScreenWidth())
		{
			delete flyEnemy;
			flyEnemy = new FlyEnemy(unit, map);
		}
	}


	void Map::draw()
	{
		DrawRectangleRec(map, tint);
		clouds->draw();
		bg->draw();
		player->draw();
		obs->draw();
		flyEnemy->draw();


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
			player->flicker();

		for (int i = 0; i < maxBullets; i++)
		{
			if (CheckCollisionCircleRec(player->getBullet(i)->getPos(), static_cast<float>(player->getBullet(i)->getRadius()), Rectangle{ flyEnemy->getPos().x, flyEnemy->getPos().y, flyEnemy->getSize().x, flyEnemy->getSize().y }))
			{
				player->getBullet(i)->setActive(false, player->getX(), player->getY());
				flyEnemy->restart();
			}


		}


	}
}