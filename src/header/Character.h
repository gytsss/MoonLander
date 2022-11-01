#pragma once

#include "Topo.h"

class Character
{
private:
	float floorHeight;
	bool inAir;
	float velocity;
	float jumpForce;
	float grav;
	
	Rectangle dest;
	Color tint;

public:
	Character(float unit, Rectangle map);
	~Character();

	void update(float unit, Rectangle map);
	void draw();

	float getY();

	void jump(float multiplier, float unit);
	void move(float unit);
};
