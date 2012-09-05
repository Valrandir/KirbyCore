#include <Core.h>
#include "Field.h"
#include "BlockMkr.h"

Field::Field()
{
	squareWidth = 10;
	squareHeight = 20;

	Grid::Create(squareWidth, squareHeight);
	Set(squareWidth / 2, squareHeight / 2, 0xffffff);
	piece.Reset(squareWidth);

	RandomFill();
}

void Field::Update()
{
	piece.Fall();

	FieldItem const *vItem;
	int nItem;

	piece.GetItems(&vItem, &nItem);
	for(int i = 0; i < nItem; ++i)
		if(vItem[i].y >= squareHeight)
		{
			piece.Reset(squareWidth);
			break;
		}
}

void Field::RandomFill()
{
	int* ptr = Grid::GetWritePtr();
	int* end = ptr + squareWidth * squareHeight;

	for(; ptr < end; ++ptr)
		*ptr = BlockMkr::GetRandomBlock();
}

void Field::GetFieldItems(FieldItem const **vItem, int* nItem) const
{
	piece.GetItems(vItem, nItem);
}
