#include <vector>
#include "Polyomino.h"

using namespace Core;
using namespace std;

const int Polyomino::ring[8] = {-1, 0, 1, -1, 1, 1, -1, 1};

int Polyomino::Iterate(VecItem *vecItem, int id)
{
	Item item;
	int i, sum = 1;

	item = vecItem->back();
	destGrid->Set(item.x, item.y, 1);

	for(i = 0; i < 8; i += 2)
	{
		item.x += ring[i];
		item.y += ring[i + 1];
		if(srcGrid->Get(item.x, item.y) == id && !destGrid->Get(item.x, item.y))
		{
			vecItem->push_back(item);
			sum += Iterate(vecItem, id);
		}
	}

	return sum;
}

void Polyomino::VecToDest(VecItem const *vecItem, int total)
{
	auto it = vecItem->begin();
	auto end = vecItem->end();
	while(it < end)
	{
		destGrid->Set(it->x, it->y, total);
		++it;
	}
}

Polyomino::Polyomino() : destGrid(0){}

Polyomino::~Polyomino()
{
	if(destGrid)
		delete destGrid;
}

Grid const* Polyomino::Detect(Grid const* srcGrid)
{
	VecItem vec;
	Item item = {0};
	int const *src;
	int const *dest;
	int sizeX, sizeY;
	int total;

	vec.reserve(16);

	this->srcGrid = srcGrid;
	destGrid = new Grid();
	destGrid->Create(srcGrid->GetSizeX(), srcGrid->GetSizeY());

	srcGrid->GetReadPtr(&src, 0, 0);
	destGrid->GetReadPtr(&dest, 0, 0);
	destGrid->GetSize(sizeX, sizeY);

	for(item.y = 0; item.y < sizeY; ++item.y)
		for(item.x = 0; item.x < sizeX; ++item.x, ++src, ++dest)
			if(*src && !*dest)
			{
				vec.push_back(item);
				total = Iterate(&vec, *src);
				VecToDest(&vec, total);
				vec.clear();
			}

	return destGrid;
}
