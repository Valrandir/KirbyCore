#include <Core.h>
#include "FieldPiece.h"
#include "BlockMkr.h"

FieldPiece::FieldPiece()
{
	end = vFieldItem + nFieldItem;
}

void FieldPiece::VMove(int y)
{
	FieldItem* p;
	for(p = vFieldItem; p < end; ++p)
		p->y += y;
}

void FieldPiece::Fall()
{
	VMove(1);
}

void FieldPiece::FlyUp()
{
	VMove(-1);
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
