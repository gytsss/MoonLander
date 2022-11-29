#pragma once

#include "extras/Topo.h"
#include "objects/Character.h"
#include "objects/Obstacle.h"
#include "objects/Background.h"
#include "objects/Clouds.h"
#include "objects/Bullets.h"
#include "objects/FlyEnemy.h"
#include "extras/Enums.h"


namespace Topo
{

	class Map
	{
	private:
		float unit;
		bool isFinished;
		bool isMultiplayer;
		bool isRunning;

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
		bool getIsRunning();
		bool getmulti();

		void update(Scenes& activeScene);
		void draw();

		void input();

		void checkCollisions();
		void setMultiplayer(bool areTwoPlayers);
		void setIsFinished(bool finish);
	};
}