#pragma once
#include <Core.h>
#include "FieldPiece.h"
#include "Polyomino/Polyomino.h"

class Field : public Core::Grid
{
	static const int DeletedFlag = -1;
	int squareWidth;
	int squareHeight;
	int threshold;
	FieldPiece piece;
	Polyomino polyomino;
	int FallCount, FallSpeed;
	int polyTotal, scoreTotal;

	public:
	Field();
	void PieceMoveLeft();
	void PieceMoveRight();
	void PieceMoveDown();
	void PieceRotateLeft();
	void PieceRotateRight();
	void PieceDropDown();
	void Update();

	private:
	void RandomFill();
	void Cycle();
	bool FindImpact();
	void SetPiece(FieldPiece const* piece);
	int DestroyItems(Core::Grid const* outGrid, int threshold);
	void Collapse();

	public:
	void GetFieldItems(FieldItem const **vItem, int* nItem) const;
	int GetPolyTotal() const;
	int GetScoreTotal() const;
};
