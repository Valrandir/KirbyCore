#pragma once
#include <Core.h>
#include "FieldPiece.h"

class Field : public Core::Grid
{
	int squareWidth;
	int squareHeight;
	FieldPiece piece;

	public:
	Field();
	void Update();

	private:
	void RandomFill();

	public:
	void GetFieldItems(FieldItem const **vItem, int* nItem) const;
};
