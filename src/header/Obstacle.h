#pragma once

#include "Parallax.h"
#include "Topo.h"

namespace Topo
{
	class Obstacle
	{
	private:
		float floorHeight;
		float speed;
		float startX;

		Rectangle col;
		Color tint;
		Parallax* parallax;

	public:
		Obstacle(float unit, Rectangle map);
		~Obstacle();

		void update(float unit, Rectangle map);
		void draw();

		Rectangle getCol();

		bool isBehindPlayer();
		void updateParallax(float unit, float playerYDif);
	};
}