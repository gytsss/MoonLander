#pragma once

#include "extras/Topo.h"

#include "Bullets.h"

namespace Topo
{
	class Character
	{
	private:
	
		float floorHeight;
		bool inAir;
		float velocity;
		float jumpForce;
		float grav;
		int currentBullets;
		int score;
		bool isAlive;
		

		Rectangle dest;
		Color tint;
		Color scoreTint;
		Bullet* bullets[maxBullets];

	public:
		Character(float unit, Rectangle map);
		~Character();

		void update(float unit, Rectangle map);
		void draw();

		float getX();
		float getY();
		Rectangle getDest();
		Bullet* getBullet(int i);
		int getScore();
		bool getIsAlive();
		Color getScoreTint();

		void jump( float unit);
		void move(float unit);
		void shoot();
		void increaseScore(int score);
		void setAlive(bool alive);
		void setDestX(float x);
		void setColor(Color color);

	};
}