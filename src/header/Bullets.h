#pragma once
#include "raylib.h"


const int maxBullets = 20;

namespace Topo
{
	class Bullet 
	{
	private:
		float x;
		float y;
		float radius;
		bool isActive;
		Vector2 speed;

	public:

		Bullet(float x, float y);
		~Bullet();

		void draw();
		void update();
		bool getActive();
		void setActive(bool isActive);
		void resetPosition();

	};
}





