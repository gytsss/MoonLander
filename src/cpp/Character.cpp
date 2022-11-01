#include "Character.h"

Character::Character(float unit, Rectangle map)
{
	floorHeight = map.y + map.height;
	inAir = false;
	velocity = 0;
	jumpForce = 4;
	grav = -10;

	dest.width = 10 * unit;
	dest.height = 10 * unit;
	dest.x = 20 * unit;
	dest.y = floorHeight;

	tint = BLUE;
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
		tint = BLUE;
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