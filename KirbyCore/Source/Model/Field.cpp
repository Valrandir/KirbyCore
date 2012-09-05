#include <Core.h>
#include "Field.h"
#include "BlockMkr.h"

Field::Field()
{
	squareWidth = 10;
	squareHeight = 20;

	Grid::Create(squareWidth, squareHeight);
	//Set(squareWidth / 2, squareHeight / 2, 0xffffff);
	piece.Reset(squareWidth);

	//RandomFill();
}

void Field::Update()
{
	FieldItem const *ptr, *end;

	piece.GetItems(&ptr, &end, 0);
	piece.Fall();

	for(; ptr < end; ++ptr)
		if(ptr->y >= squareHeight || Get(ptr->x, ptr->y))
		{
			piece.FlyUp();
			SetPiece(&piece);
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

void Field::SetPiece(FieldPiece const * piece)
{
	FieldItem const *ptr, *end;

	piece->GetItems(&ptr, &end, 0);

	for(; ptr < end; ++ptr)
		Set(ptr->x, ptr->y, ptr->color);
}

void Field::GetFieldItems(FieldItem const **vItem, int* nItem) const
{
	piece.GetItems(vItem, 0, nItem);
}
