#pragma once
#pragma once
#include "raylib.h"
#include "Parallax.h"

namespace Topo
{

	class FlyEnemy
	{
	private:
		float floorHeight;
		float startX;
		float force;
		int topMove;
		int downMove;


		Vector2 pos;
		Vector2 speed;
		Vector2 size;

		Parallax* parallax;

	public:
		FlyEnemy(float unit, Rectangle map);
		~FlyEnemy();

		void draw();
		void update(float unit);
		void updateParallax(float playerYDif);
		void restart();
		
		Vector2 getPos();
		Vector2 getSize();


	};
}
