#pragma once
#include <Core.h>
#include "FieldPiece.h"
#include "Polyomino/Polyomino.h"

class Field : public Core::Grid
{
	static const int DeletedFlag = -1;
	int squareWidth;
	int squareHeight;
	FieldPiece piece;
	Polyomino polyomino;

	public:
	Field();
	void Update();

	private:
	void RandomFill();
	bool FindImpact();
	void SetPiece(FieldPiece const* piece);
	void DestroyItems(Core::Grid const* outGrid, int threshold);
	void Collapse();

	public:
	void GetFieldItems(FieldItem const **vItem, int* nItem) const;
};
