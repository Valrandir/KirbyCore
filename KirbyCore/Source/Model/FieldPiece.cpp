#include <Core.h>
#include "FieldPiece.h"
#include "BlockMkr.h"

FieldPiece::FieldPiece() : end(vFieldItem + nFieldItem) {}

void FieldPiece::Translate(int x, int y)
{
	FieldItem* p = vFieldItem;
	while(p < end)
	{
		p->x += x;
		p->y += y;
		++p;
	}
}

void FieldPiece::RotateZero(int direction)
{
	int xSwap;
	FieldItem* p = vFieldItem;

	while(p < end)
	{
		xSwap = p->x;
		p->x = p->y;
		p->y = xSwap;

		if(direction > 0)
			p->x = -p->x;
		else
			p->y = -p->y;

		++p;
	}
}

void FieldPiece::Rotate(int direction)
{
	int x = vFieldItem->x;
	int y = vFieldItem->y;

	Translate(-x, -y);
	RotateZero(direction);
	Translate(x, y);
}

void FieldPiece::MoveLeft()
{
	Translate(-1, 0);
}

void FieldPiece::MoveRight()
{
	Translate(1, 0);
}

void FieldPiece::MoveUp()
{
	Translate(0, -1);
}

void FieldPiece::MoveDown()
{
	Translate(0, 1);
}

void FieldPiece::RotateLeft()
{
	Rotate(-1);
}

void FieldPiece::RotateRight()
{
	Rotate(1);
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
