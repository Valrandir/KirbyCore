#pragma once
#include <Core.h>

class Field : public Core::Grid
{
	int squareWidth;
	int squareHeight;

	int fallingX;
	int fallingY;
	int fallingColor;

	public:
	Field();
	void Update();

	private:
	void RandomFill();

	public:
	void GetFallingInfo(int& x, int& y, int& color) const;
};
