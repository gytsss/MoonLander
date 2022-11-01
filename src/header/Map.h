#pragma once

#include "Character.h"
#include "Topo.h"
#include "Obstacle.h"

class Map
{
private:
	float unit;
	float jFMultiplier;

	Rectangle map;
	Color tint;
	Character* player;
	Obstacle* obs;

public:
	Map();
	~Map();

	Vector2 getSize();
	float getPosY();
	float getHeight();
	float getWidth();

	void update();
	void draw();

	void input();
};