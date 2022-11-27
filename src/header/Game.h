#pragma once

#include "Map.h"
#include "Topo.h"



namespace Topo
{
	
	class Game
	{

	private:
		bool isPlaying;

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
	};
}