#include "Obstacle.h"

namespace Topo
{
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
		parallax = new Parallax(0);
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

	Rectangle Obstacle::getCol()
	{
		return col;
	}

	bool Obstacle::isBehindPlayer()
	{
		return col.x + col.width < 0;
	}

	void Obstacle::updateParallax( float playerYDif)
	{
		parallax->update( col.y, playerYDif);
	}
}