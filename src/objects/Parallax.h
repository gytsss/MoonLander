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

		void update(float& y, float playerYDif);
	};
}