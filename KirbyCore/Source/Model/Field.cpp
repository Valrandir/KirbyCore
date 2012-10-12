#include <Core.h>
#include "Field.h"
#include "BlockMkr.h"

void Field::RandomFill()
{
	int* ptr;
	int* end;

	GetWritePtr(&ptr, &end, 0);
	for(; ptr < end; ++ptr)
		*ptr = BlockMkr::GetRandomBlock();
}

bool Field::PieceRotate(bool clockwise)
{
	piece.Rotate(clockwise);
	if(!FindImpact()) return true;

	piece.Offset(1, 0);
	if(!FindImpact()) return true;

	piece.Offset(-2, 0);
	if(!FindImpact()) return true;

	piece.Offset(1, 0);
	piece.Rotate(!clockwise);
	return false;
}

void Field::Cycle()
{
	int polyCount;
	Grid const* outGrid;

	SetPiece(&piece);
	piece.Reset(squareWidth);

	while(polyCount = polyomino.Detect(this, &outGrid, threshold))
	{
		polyTotal += polyCount;
		scoreTotal += DestroyItems(outGrid, threshold);
		Collapse();
	}
}

bool Field::FindImpact()
{
	FieldItem const *ptr, *end;
	piece.GetItems(&ptr, &end, 0);

	for(; ptr < end; ++ptr)
		if(ptr->x < 0 || ptr->x >= squareWidth || ptr->y >= squareHeight || Get(ptr->x, ptr->y))
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

int Field::DestroyItems(Core::Grid const* outGrid, int threshold)
{
	int *src, n, i;
	int const* out;
	int total = 0;

	GetWritePtr(&src, 0, &n);
	outGrid->GetReadPtr(&out, 0, 0);

	for(i = 0; i < n; ++i, ++src, ++out)
		if(*out >= threshold)
		{
			*src = DeletedFlag;
			++total;
		}

	return total;
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

Field::Field() : polyTotal(0), scoreTotal(0)
{
	squareWidth = 6;
	squareHeight = 12;
	threshold = 4;

	FallCount = 0;
	FallSpeed = 5;

	Grid::Create(squareWidth, squareHeight);
	piece.Reset(squareWidth);
}

void Field::PieceMoveLeft()
{
	piece.Offset(-1, 0);
	if(FindImpact())
		piece.Offset(1, 0);
}

void Field::PieceMoveRight()
{
	piece.Offset(1, 0);
	if(FindImpact())
		piece.Offset(-1, 0);
}

void Field::PieceMoveDown()
{
	piece.Offset(0, 1);
	if(FindImpact())
	{
		piece.Offset(0, -1);
		Cycle();
	}
}

void Field::PieceRotateLeft()
{
	PieceRotate(false);
}

void Field::PieceRotateRight()
{
	PieceRotate(true);
}

void Field::PieceDropDown()
{
	do piece.Offset(0, 1);
	while(!FindImpact());
	piece.Offset(0, -1);
	Cycle();
}

void Field::Update()
{
	if(++FallCount >= FallSpeed)
	{
		FallCount = 0;
		PieceMoveDown();
	}
}

void Field::GetFieldItems(FieldItem const **vItem, int* nItem) const
{
	piece.GetItems(vItem, 0, nItem);
}

int Field::GetPolyTotal() const
{
	return polyTotal;
}

int Field::GetScoreTotal() const
{
	return scoreTotal;
}
