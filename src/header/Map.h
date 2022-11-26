#pragma once

#include "Topo.h"
#include "Character.h"
#include "Obstacle.h"
#include "Background.h"
#include "Clouds.h"
#include "Bullets.h"

namespace Topo
{

	class Map
	{
	private:
		float unit;
		float jFMultiplier;

		Rectangle map;
		Color tint;
		Character* player;
		Obstacle* obs;
		Background* bg;
		Clouds* clouds;
	

	public:
		Map();
		~Map();

		Vector2 getSize();
		float getPosY();
		float getHeight();
		float getWidth();
		float getUnit();

		void update();
		void draw();

		void input();

		void checkCollisions();
	};
}