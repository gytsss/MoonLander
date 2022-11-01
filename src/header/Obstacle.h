#pragma once

#include "Topo.h"

class Obstacle
{
private:
	float floorHeight;
	float speed;
	float startX;

	Rectangle col;
	Color tint;

public:
	Obstacle(float unit, Rectangle map);
	~Obstacle();

	void update(float unit, Rectangle map);
	void draw();

	bool isBehindPlayer();
};