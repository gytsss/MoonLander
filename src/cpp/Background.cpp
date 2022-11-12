#include "Background.h"

namespace Topo
{
	Background::Background(Rectangle map)
	{
		zoom = 50;
		speed = 80;

		parallax = new Parallax(1);

		dest[0].x = map.x - zoom;
		dest[0].y = map.y - zoom;
		dest[0].width = map.width + 2 * zoom;
		dest[0].height = map.height + 2 * zoom;

		dest[1].x = dest[0].x + dest[0].width;
		dest[1].y = map.y - zoom;
		dest[1].width = map.width + 2 * zoom;
		dest[1].height = map.height + 2 * zoom;

		image = LoadTexture("res/Trees.png");

		tint = BLACK;
	}

	Background::~Background()
	{
		UnloadTexture(image);
		delete parallax;
	}

	void Background::draw()
	{
		Rectangle source{ 0, 0, static_cast<float>(image.width),
			static_cast<float>(image.height) };

		for (int i = 0; i < 2; i++)
		{
			DrawTexturePro(image, source, dest[i], { 0, 0 }, 0, tint);
		}
	}

	void Background::update(float unit, Rectangle map)
	{
		dest[0].width = map.width + 2 * zoom;
		dest[0].height = map.height + 2 * zoom;

		dest[1].width = map.width + 2 * zoom;
		dest[1].height = map.height + 2 * zoom;

		for (int i = 0; i < 2; i++)
		{
			dest[i].x -= speed * unit * GetFrameTime();

			if (dest[i].x + dest[i].width < 0)
				dest[i].x = map.width;
		}
	}

	void Background::updateParallax(float unit, float playerYDif)
	{
		for (int i = 0; i < 2; i++)
		{
			parallax->update(unit, dest[i].y, playerYDif);
		}
	}
}