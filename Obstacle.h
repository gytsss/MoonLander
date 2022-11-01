#pragma once

#include "Topo.h"

class Obstacle
{
private:
	float floorHeight;
	float speed;

	Rectangle collider;
	Vector2 pos;
	Color tint;

public:
	Obstacle(float unit, Rectangle map);
	~Obstacle();

	void update(float unit);
	void draw();
};