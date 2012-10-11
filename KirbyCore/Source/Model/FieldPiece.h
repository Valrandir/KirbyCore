#pragma once
#include "FieldItem.h"

class FieldPiece
{
	static const int nFieldItem = 2;
	FieldItem vFieldItem[nFieldItem];
	FieldItem const * const end;

	public:
	FieldPiece();

	private:
	void RotateZero(bool clockwise);

	public:
	void Offset(int x, int y);
	void Rotate(bool clockwise);
	void Reset(int fieldSquareWidth);
	void GetItems(FieldItem const **begin, FieldItem const **end, int* count) const;
};
