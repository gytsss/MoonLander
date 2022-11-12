#include "Clouds.h"

namespace Topo
{
	Clouds::Clouds(Rectangle map)
	{
		zoom = 50;
		speed = 40;

		parallax = new Parallax(2);


		for (int i = 0; i < 2; i++)
		{
			dest[i].x = i == 0 ? map.x - zoom : (dest[0].x + dest[0].width);
			dest[i].y = map.y - zoom;
			dest[i].width = map.width + 2 * zoom;
			dest[i].height = map.height + 2 * zoom;

		}
		image = LoadTexture("res/Clouds.png");

		tint = WHITE;
	}

	Clouds::~Clouds()
	{
		UnloadTexture(image);
		delete parallax;
	}

	void Clouds::draw()
	{
		Rectangle source{ 0, 0, static_cast<float>(image.width),
			static_cast<float>(image.height) };

		for (int i = 0; i < 2; i++)
		{
			DrawTexturePro(image, source, dest[i], { 0, 0 }, 0, tint);
		}
	}

	void Clouds::update(float unit, Rectangle map)
	{
		for (int i = 0; i < 2; i++)
		{
			dest[i].width = map.width + 2 * zoom;
			dest[i].height = (map.height + 2 * zoom) / 2;
		}

		for (int i = 0; i < 2; i++)
		{
			dest[i].x -= speed * unit * GetFrameTime();

			if (dest[i].x + dest[i].width < 0)
				dest[i].x = map.width;
		}
	}

	void Clouds::updateParallax(float unit, float playerYDif)
	{
		for (int i = 0; i < 2; i++)
		{
			parallax->update(unit, dest[i].y, playerYDif);
		}
	}
}