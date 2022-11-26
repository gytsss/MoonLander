#include "Character.h"


namespace Topo
{
	Character::Character(float unit, Rectangle map)
	{
		ghostTime = 2;
		flickerTime = .5f;
		floorHeight = map.y + map.height;
		inAir = false;
		velocity = 0;
		jumpForce = 4;
		grav = -10;
		ghost = false;
		ghostCounter = ghostTime;
		flickerCounter = flickerTime;
		currentBullets = 0;
		score = 0;

		dest.width = 10 * unit;
		dest.height = 10 * unit;
		dest.x = 20 * unit;
		dest.y = floorHeight;

		tint = WHITE;

		for (int i = 0; i < maxBullets; i++)
		{
			bullets[i] = new Bullet(dest.x, dest.y);

		}
	}

	Character::~Character()
	{
		for (int i = 0; i < maxBullets; i++)
		{
			delete bullets[i];
		}

	}

	void Character::update(float unit, Rectangle map)
	{
		floorHeight = map.y + map.height;

		dest.width = 10 * unit;
		dest.height = 10 * unit;

		move(unit);

		if (dest.y + dest.height >= floorHeight)
		{
			inAir = false;
		}

		if (ghost)
		{
			tint.a = tint.a == 255 ? 100 : 255;
			ghostCounter -= GetFrameTime();
		}

		if (ghostCounter <= 0)
		{
			ghostCounter = ghostTime;
			ghost = false;
			tint.a = 255;
		}

		for (int i = 0; i < maxBullets; i++)
		{
			bullets[i]->update(unit);
		}
	}

	void Character::draw()
	{
		DrawRectangleRec(dest, tint);
		for (int i = 0; i < maxBullets; i++)
		{
			bullets[i]->draw();
		}
	}

	float Character::getX()
	{

		return dest.x;
	}

	float Character::getY()
	{

		return dest.y;
	}

	Rectangle Character::getDest()
	{
		return dest;
	}

	void Character::jump(float multiplier, float unit)
	{
		if (!inAir)
		{
			inAir = true;
			velocity += jumpForce * unit * multiplier;
		}
	}

	void Character::move(float unit)
	{
		if (inAir)
		{
			velocity += grav * unit * GetFrameTime();
		}
		else
		{
			velocity = 0;
			dest.y = floorHeight - dest.height;
		}

		dest.y -= velocity * unit * GetFrameTime();
	}

	void Character::flicker()
	{
		ghostCounter = ghostTime;
		ghost = true;
	}

	void Character::shoot()
	{
		
		if (currentBullets >= maxBullets)
		{
			currentBullets = 0;
		}
		

		bullets[currentBullets]->setActive(true, dest.x + dest.width / 4 , dest.y);
		currentBullets++;

	}
	void Character::increaseScore(float scoreToIncrease)
	{
		this->score += scoreToIncrease;
	}
}