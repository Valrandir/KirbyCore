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
	void HMove(int x);
	void VMove(int y);

	public:
	void MoveLeft();
	void MoveRight();
	void Fall();
	void FlyUp();
	void Reset(int fieldSquareWidth);
	void GetItems(FieldItem const **begin, FieldItem const **end, int* count) const;
};
