#include "FlyEnemy.h"

namespace Topo
{

	FlyEnemy::FlyEnemy(float unit, Rectangle map)
	{
		floorHeight = map.y + map.height;
		speed = { 30, 50 };
		startX = -10;

		size.x = 10 * unit;
		size.y = 10 * unit;

		pos.x = startX;
		pos.y = 30 * unit;

		topMove = 15;
		downMove = 50;

		force = 1;

		parallax = new Parallax(0);
	}

	FlyEnemy::~FlyEnemy()
	{
	}

	void FlyEnemy::draw()
	{
		DrawRectangle(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(size.x), static_cast<int>(size.y), PURPLE);
	}

	void FlyEnemy::update(float unit)
	{
		startX = -50;

		size.x = 10 * unit;
		size.y = 10 * unit;

		if (pos.y > downMove * unit)
		{
			force = -force;
		}

		if (pos.y < topMove * unit)
		{
			force = -force;
		}

		pos.x += speed.x * unit * GetFrameTime();
		pos.y += speed.y * unit * force * GetFrameTime();

	}

	Vector2 FlyEnemy::getPos()
	{
		return pos;
	}

	Vector2 FlyEnemy::getSize()
	{
		return size;
	}

	void FlyEnemy::restart()
	{
		pos.x = startX;
	}

	void FlyEnemy::updateParallax(float playerYDif)
	{
		parallax->update(pos.y, playerYDif);
	}

}