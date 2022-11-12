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

		dest.width = 10 * unit;
		dest.height = 10 * unit;
		dest.x = 20 * unit;
		dest.y = floorHeight;

		tint = WHITE;
	}

	Character::~Character()
	{
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
	}

	void Character::draw()
	{
		DrawRectangleRec(dest, tint);
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
}