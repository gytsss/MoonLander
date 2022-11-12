#include "Parallax.h"

namespace Topo
{
	Parallax::Parallax(int layer)
	{
		this->layer = layer;
	}

	Parallax::~Parallax()
	{
	}

	void Parallax::update(float unit, float& y, float playerYDif)
	{
		y += playerYDif * static_cast<float>(layer) / 8;
	}
}