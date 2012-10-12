#include <Core.h>
#include "FieldPiece.h"
#include "BlockMkr.h"

FieldPiece::FieldPiece() : end(vFieldItem + nFieldItem) {}

void FieldPiece::RotateZero(bool clockwise)
{
	int swap;
	FieldItem* p = vFieldItem;

	while(p < end)
	{
		swap = p->x;
		p->x = p->y;
		p->y = swap;

		int& pt = clockwise ? p->x : p->y;
		pt = -pt;

		++p;
	}
}

void FieldPiece::Offset(int x, int y)
{
	FieldItem* p = vFieldItem;
	while(p < end)
	{
		p->x += x;
		p->y += y;
		++p;
	}
}

void FieldPiece::Rotate(bool clockwise)
{
	int x = vFieldItem->x;
	int y = vFieldItem->y;

	Offset(-x, -y);
	RotateZero(clockwise);
	Offset(x, y);
}

void FieldPiece::Reset(int fieldSquareWidth)
{
	int x = Core::Random::Rnd(0, fieldSquareWidth - 1);
	int y = 0;
	int color = BlockMkr::GetRandomBlock();

	for(int i = 0; i < nFieldItem; ++i)
	{
		vFieldItem[i].x = x;
		vFieldItem[i].y = y + i;
		vFieldItem[i].color = color;
	}
}

void FieldPiece::GetItems(FieldItem const **begin, FieldItem const **end, int* count) const
{
	if(begin)
		*begin = vFieldItem;

	if(end)
		*end = vFieldItem + nFieldItem;

	if(count)
		*count = nFieldItem;
}
