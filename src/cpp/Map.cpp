#include "Map.h"

Map::Map()
{
	const float screenWidth = static_cast<float>(GetScreenWidth());
	const float screenHeight = static_cast<float>(GetScreenHeight());

	unit = screenWidth / 160;
	jFMultiplier = 1;

	map.width = screenWidth;
	map.height = 90 * unit;
	map.x = 0;
	map.y = screenHeight / 2 - map.height / 2;

	tint = WHITE;

	player = new Character(unit, map);
	obs = new Obstacle(unit, map);
}

Map::~Map()
{
	delete player;
	delete obs;
}

Vector2 Map::getSize()
{
	return {map.width, map.height};
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

void Map::update()
{
	const float screenWidth = static_cast<float>(GetScreenWidth());
	const float screenHeight = static_cast<float>(GetScreenHeight());

	unit = screenWidth / 160;

	map.width = screenWidth;
	map.height = 90 * unit;
	map.x = 0;
	map.y = screenHeight / 2 - map.height / 2;

	input();
	player->update(unit, map);
	obs->update(unit, map);

	if (obs->isBehindPlayer())
	{
		delete obs;
		obs = new Obstacle(unit, map);
	}
}

void Map::draw()
{
	DrawRectangleRec(map, tint);
	player->draw();
	obs->draw();
}

void Map::input()
{
	if (IsKeyReleased(KEY_SPACE) || (IsKeyDown(KEY_SPACE) && jFMultiplier >= 2))
	{
		player->jump(jFMultiplier, unit);
		jFMultiplier = 1;
	}

	if (IsKeyDown(KEY_SPACE))
		jFMultiplier += GetFrameTime() * 2;
}