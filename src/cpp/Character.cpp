#include "Character.h"


namespace Topo
{
	Character::Character(float unit, Rectangle map)
	{
		floorHeight = map.y + map.height;
		inAir = false;
		velocity = 0;
		jumpForce = 10;
		grav = -15;
		ghost = false;
		currentBullets = 0;
		score = 0;
		isAlive = true;

		dest.width = 10 * unit;
		dest.height = 10 * unit;
		dest.x = 20 * unit;
		dest.y = floorHeight;

		tint = WHITE;
		scoreTint = { 218,165,32,255 };

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

	Bullet* Character::getBullet(int i)
	{
		return bullets[i];
	}

	int Character::getScore()
	{
		return score;
	}

	bool Character::getIsAlive()
	{
		if (isAlive)
			return true;
		else
			return false;
	}

	Color Character::getScoreTint()
	{
		return scoreTint;
	}

	void Character::jump(float unit)
	{
		if (!inAir)
		{
			inAir = true;
			velocity += jumpForce * unit;
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


	void Character::shoot()
	{

		if (currentBullets >= maxBullets)
		{
			currentBullets = 0;
		}


		bullets[currentBullets]->setActive(true, dest.x + dest.width / 4, dest.y);
		currentBullets++;

	}
	void Character::increaseScore(int scoreToIncrease)
	{
		this->score += scoreToIncrease;
	}
	void Character::setAlive(bool alive)
	{
		isAlive = alive;
	}
}