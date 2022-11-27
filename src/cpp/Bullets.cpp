#include "Bullets.h"

namespace Topo
{

	Bullet::Bullet(float x, float y) 
	{
		radius = 5;
		this->x = x;
		this->y = y;
		isActive = false;


		speed.x = 20;
		speed.y = 70;

	}

	Bullet::~Bullet()
	{
	}

	void Bullet::draw()
	{
		if (isActive)
		{
			DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<float>(radius), RED);
		}
	}

	void Bullet::update(float unit)
	{
		if (isActive)
		{
			x += speed.x * unit * GetFrameTime();
			y -= speed.y * unit * GetFrameTime();
		}
	}
	bool Bullet::getActive()
	{
		return isActive;
	}

	void Bullet::setActive(bool active, float posX, float posY)
	{
		this->isActive = active;
		this->x = posX;
		this->y = posY;
	}

	int Bullet::getRadius()
	{
		return radius;
	}

	Vector2 Bullet::getPos()
	{
		return Vector2{ x , y };
	}
	
}
