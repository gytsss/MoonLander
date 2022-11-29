#pragma once
#include "extras/Topo.h"

#include "Parallax.h"

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
		void updateParallax( float playerYDif);
	};
}