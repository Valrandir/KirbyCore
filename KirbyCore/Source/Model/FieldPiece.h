#pragma once
#include "FieldItem.h"

class FieldPiece
{
	static const int nFieldItem = 3;
	FieldItem vFieldItem[nFieldItem];
	FieldItem* end;

	public:
	FieldPiece();

	private:
	void VMove(int y);

	public:
	void Fall();
	void FlyUp();
	void Reset(int fieldSquareWidth);
	void GetItems(FieldItem const **begin, FieldItem const **end, int* count) const;
};
