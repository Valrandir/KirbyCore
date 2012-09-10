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
	void Translate(int x, int y);
	void RotateZero(int direction);
	void Rotate(int direction);

	public:
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void RotateLeft();
	void RotateRight();
	void Reset(int fieldSquareWidth);
	void GetItems(FieldItem const **begin, FieldItem const **end, int* count) const;
};
