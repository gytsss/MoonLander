#pragma once
#include "Parallax.h"
#include "Topo.h"

namespace Topo
{
	class Clouds
	{
	private:
		float zoom;
		float speed;

		Parallax* parallax;
		Rectangle dest[2];
		Texture2D image;
		Color tint;

	public:
		Clouds(Rectangle map);
		~Clouds();

		void draw();
		void update(float unit, Rectangle map);
		void updateParallax(float unit, float playerYDif);
	};
}