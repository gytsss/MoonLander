#include "Character.h"

Character::Character(float unit, Rectangle map)
{
	floorHeight = map.y + map.height - 10 * unit;
	inAir = false;
	velocity = 0;
	jumpForce = 40;
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
	dest.width = 10 * unit;
	dest.height = 10 * unit;

	move(unit);

	if (dest.y + dest.height >= map.height + map.y)
	{
		inAir = false;
		tint = BLUE;
	}
}

void Character::draw()
{
	DrawRectangleRec(dest, tint);
}

void Character::jump(float multiplier)
{
	if (!inAir)
	{
		inAir = true;
		velocity += jumpForce * multiplier;
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
		dest.y = floorHeight;
	}

	dest.y -= velocity * unit * GetFrameTime();
}