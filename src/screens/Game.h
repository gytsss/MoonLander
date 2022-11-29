#pragma once

#include "Map.h"
#include "extras/Topo.h"



namespace Topo
{
	
	class Game
	{

	private:
		bool isPlaying;
		bool isMultiplayer;

		Map* map;
		Scenes scenes;

	public:
		Game();
		~Game();

		void loop();
		void play();
		void menu();
		void credits();

		void begin();
		void update();
		void draw();
		void input();
	};


	void defaults();
	void runProgram();
}