#pragma once

#include "Parallax.h"
#include "Topo.h"

class Background
{
private:
	float zoom;
	float speed;

	Parallax* parallax;
	Rectangle dest[2];
	Texture2D image;
	Color tint;

public:
	Background(Rectangle map);
	~Background();

	void draw();
	void update(float unit, Rectangle map);
	void updateParallax(float unit, float playerYDif);
};