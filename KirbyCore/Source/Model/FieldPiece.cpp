#include <Core.h>
#include "FieldPiece.h"
#include "BlockMkr.h"

FieldPiece::FieldPiece()
{
	end = vFieldItem + nFieldItem;
}

void FieldPiece::Fall()
{
	FieldItem* p;
	for(p = vFieldItem; p < end; ++p)
		++(p->y);
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

void FieldPiece::GetItems(FieldItem const **vItem, int* nItem) const
{
	*vItem = vFieldItem;
	*nItem = nFieldItem;
}
