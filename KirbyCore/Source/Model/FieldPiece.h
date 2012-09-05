#pragma once
#include "FieldItem.h"

class FieldPiece
{
	static const int nFieldItem = 7;
	FieldItem vFieldItem[nFieldItem];
	FieldItem* end;

	public:
	FieldPiece();
	void Fall();
	void Reset(int fieldSquareWidth);
	void GetItems(FieldItem const **vItem, int* nItem) const;
};
