#pragma once

#include "Topo.h"

namespace Topo
{
	class Character
	{
	private:
		float ghostTime;
		float flickerTime;
		float floorHeight;
		bool inAir;
		float velocity;
		float jumpForce;
		float grav;
		bool ghost;
		float ghostCounter;
		float flickerCounter;

		Rectangle dest;
		Color tint;

	public:
		Character(float unit, Rectangle map);
		~Character();

		void update(float unit, Rectangle map);
		void draw();

		float getY();
		Rectangle getDest();

		void jump(float multiplier, float unit);
		void move(float unit);
		void flicker();
	};
}