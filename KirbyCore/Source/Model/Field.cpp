#include <Core.h>
#include "Field.h"
#include "BlockMkr.h"

Field::Field()
{
	squareWidth = 8;
	squareHeight = 8;

	Grid::Create(squareWidth, squareHeight);
	piece.Reset(squareWidth);
}

void Field::Update()
{
	int threshold = 4;
	Grid const* outGrid;

	piece.Fall();

	if(FindImpact())
	{
		piece.FlyUp();
		SetPiece(&piece);
		piece.Reset(squareWidth);
		while(polyomino.Detect(this, &outGrid, threshold))
		{
			DestroyItems(outGrid, threshold);
			Collapse();
		}
	}
}

void Field::RandomFill()
{
	int* ptr;
	int* end;

	GetWritePtr(&ptr, &end, 0);
	for(; ptr < end; ++ptr)
		*ptr = BlockMkr::GetRandomBlock();
}

bool Field::FindImpact()
{
	FieldItem const *ptr, *end;
	piece.GetItems(&ptr, &end, 0);

	for(; ptr < end; ++ptr)
		if(ptr->y >= squareHeight || Get(ptr->x, ptr->y))
			return true;

	return false;
}

void Field::SetPiece(FieldPiece const* piece)
{
	FieldItem const *ptr, *end;
	piece->GetItems(&ptr, &end, 0);

	for(; ptr < end; ++ptr)
		Set(ptr->x, ptr->y, ptr->color);
}

void Field::DestroyItems(Core::Grid const* outGrid, int threshold)
{
	int *src, n, i;
	int const* out;

	GetWritePtr(&src, 0, &n);
	outGrid->GetReadPtr(&out, 0, 0);

	for(i = 0; i < n; ++i, ++src, ++out)
		if(*out >= threshold)
			*src = DeletedFlag;
}

void Field::Collapse()
{
	int x, y, sx, sy;
	int* ptr;
	int i;

	GetSize(sx, sy);
	GetWritePtr(0, &ptr, 0);

	for(y = sy - 1; y >= 0; --y)
		for(x = sx - 1; x >= 0; --x)
		{
			--ptr;
			while(*ptr == DeletedFlag)
				for(i = y; i >= 0; --i)
					Set(x, i, Get(x, i - 1));
		}
}

void Field::GetFieldItems(FieldItem const **vItem, int* nItem) const
{
	piece.GetItems(vItem, 0, nItem);
}
