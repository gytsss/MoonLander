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
		bool isFinished;
		bool isMultiplayer;
		

		Rectangle map;
		Color tint;
		Character* player;
		Character* secondPlayer;
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
		bool getIsFinished();

		void update(Scenes activeScene);
		void draw();

		void input();

		void checkCollisions();
		void setMultiplayer(bool areTwoPlayers);
	};
}