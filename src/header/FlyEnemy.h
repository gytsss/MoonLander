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

		Vector2 pos;
		Vector2 speed;
		Vector2 size;

		Parallax* parallax;

	public:
		FlyEnemy(float unit, Rectangle map);
		~FlyEnemy();

		void draw();
		void update(float unit);
		Vector2 getPos();

		void updateParallax(float playerYDif);

	};
}
