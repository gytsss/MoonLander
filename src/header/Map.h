#pragma once

#include "Topo.h"
#include "Character.h"
#include "Obstacle.h"
#include "Background.h"
#include "Clouds.h"
#include "Bullets.h"
#include "FlyEnemy.h"
#include "Enums.h"


namespace Topo
{

	class Map
	{
	private:
		float unit;
		

		Rectangle map;
		Color tint;
		Character* player;
		Obstacle* obs;
		FlyEnemy* flyEnemy;
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

		void update(Scenes activeScene);
		void draw();

		void input();

		void checkCollisions();
	};
}