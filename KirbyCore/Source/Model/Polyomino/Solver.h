#pragma once
#include <Core.h>
#include <vector>

class Solver
{
	struct Item{int x, y;};
	typedef std::vector<Item> VecItem;
	static const int ring[8];
	Core::Grid const* srcGrid;
	Core::Grid* destGrid;

	int Iterate(VecItem *vecItem, int id);
	void VecToDest(VecItem const *vecItem, int total);

	public:
	Solver();
	~Solver();
	Core::Grid const* Solve(Core::Grid const* srcGrid);
};
