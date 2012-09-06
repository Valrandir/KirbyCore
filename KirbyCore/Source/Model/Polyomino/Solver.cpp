#include <vector>
#include "Solver.h"

using namespace Core;
using namespace std;

//const int Solver::ring[8] = {0, -1, -1, 0, 1, 0, 0, 1};
const int Solver::ring[8] = {-1, 0, 1, -1, 1, 1, -1, 1};

int Solver::Iterate(VecItem *vecItem, int id)
{
	Item item;
	int count = 1;
	int i;

	item = vecItem->back();
	destGrid->Set(item.x, item.y, 1);

	for(i = 0; i < 8; i += 2)
	{
		item.x += ring[i];
		item.y += ring[i + 1];
		if(srcGrid->Get(item.x, item.y) == id && !destGrid->Get(item.x, item.y))
		{
			vecItem->push_back(item);
			count += Iterate(vecItem, id);
		}
	}

	return count;
}

void Solver::VecToDest(VecItem const *vecItem, int total)
{
	auto it = vecItem->begin();
	auto end = vecItem->end();
	while(it < end)
	{
		destGrid->Set(it->x, it->y, total);
		++it;
	}
}

Grid const* Solver::Solve(Grid const* srcGrid)
{
	VecItem vec;
	Item item = {0};
	int total;

	this->srcGrid = srcGrid;

	destGrid = new Grid();
	destGrid->Create(srcGrid->GetSizeX(), srcGrid->GetSizeY());

	vec.push_back(item);
	total = Iterate(&vec, 1);
	VecToDest(&vec, total);

	return 0;
}
