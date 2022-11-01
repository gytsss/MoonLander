#include "Obstacle.h"

Obstacle::Obstacle(float unit, Rectangle map)
{
	floorHeight = map.y + map.height;
	speed = -50;
	startX = map.width;

	col.width = 20 * unit;
	col.height = 5 * unit;
	col.x = startX;
	col.y = floorHeight - col.height;
	tint = RED;
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(float unit, Rectangle map)
{
	floorHeight = map.y + map.height;
	startX = map.width;

	col.width = 20 * unit;
	col.height = 5 * unit;

	col.x += speed * unit * GetFrameTime();
	col.y = floorHeight - col.height;
}

void Obstacle::draw()
{
	DrawRectangleRec(col, tint);
}

bool Obstacle::isBehindPlayer()
{
	return col.x + col.width < 0;
}