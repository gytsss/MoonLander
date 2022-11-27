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
		bool getActive();
		void setActive(bool isActive, float x, float y);
		int getRadius();
		Vector2 getPos();

		

	};
}





