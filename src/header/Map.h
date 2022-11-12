#pragma once

#include "Topo.h"
#include "Character.h"
#include "Obstacle.h"
#include "Background.h"
#include "Clouds.h"

namespace Topo
{
	class Clouds;

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

		void update();
		void draw();

		void input();

		void checkCollisions();
	};
}