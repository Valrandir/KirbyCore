#pragma once
#include <Core.h>
#include <vector>

class Polyomino
{
	struct Item{int x, y;};
	typedef std::vector<Item> VecItem;
	static const int ring[8];
	Core::Grid const* srcGrid;
	Core::Grid* destGrid;
	VecItem vec;

	void Initialize(Core::Grid const* srcGrid);
	int Iterate(VecItem *vecItem, int id);
	void VecToDest(VecItem const *vecItem, int total);

	public:
	Polyomino();
	~Polyomino();
	int Detect(Core::Grid const* srcGrid, Core::Grid const** outGrid, int threshold);
};
