#include "Bullets.h"

namespace Topo
{

	Bullet::Bullet(float x, float y) 
	{
		radius = 5;
		this->x = x;
		this->y = y;
		isActive = false;


		speed.x = 50;
		speed.y = 200;

	}

	Bullet::~Bullet()
	{
	}

	void Bullet::draw()
	{
		if (isActive)
		{
			DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, RED);

		}
	}

	void Bullet::update()
	{
		if (isActive)
		{
			x += speed.x * GetFrameTime();
			y -= speed.y * GetFrameTime();
		}
	}
	bool Bullet::getActive()
	{
		return isActive;
	}
	void Bullet::setActive(bool isActive)
	{
		this->isActive = isActive;
	}
	void Bullet::resetPosition()
	{
		
	}
}
