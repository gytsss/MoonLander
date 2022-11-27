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
		int radius;
		bool isActive;
		Vector2 speed;

	public:

		Bullet(float x, float y);
		~Bullet();

		void draw();
		void update(float unit);
		void setActive(bool isActive, float posX, float posY);

		bool getActive();
		int getRadius();
		Vector2 getPos();

		

	};
}





