#pragma once
namespace Topo
{
	class Parallax
	{
	private:
		int layer;

	public:
		Parallax(int layer);
		~Parallax();

		void update(float unit, float& y, float playerYDif);
	};
}