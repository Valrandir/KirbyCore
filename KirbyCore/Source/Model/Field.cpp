#include <Core.h>
#include "Field.h"
#include "BlockMkr.h"

Field::Field()
{
	squareWidth = 3;
	squareHeight = 50;

	Grid::Create(squareWidth, squareHeight);
	Set(squareWidth / 2, squareHeight / 2, 0xffffff);
	//RandomFill();

	fallingX = 0;
	fallingY = 0;
	fallingColor = 0;
}

void Field::Update()
{
	if(!fallingColor)
	{
		fallingX = Core::Random::Rnd(0, squareWidth - 1);
		fallingY = 0;
		fallingColor = BlockMkr::GetRandomBlock();
	}
	else
	{
		++fallingY;
		if(fallingY >= squareHeight)
			fallingColor = 0;
	}
}

void Field::RandomFill()
{
	int* ptr = Grid::GetWritePtr();
	int* end = ptr + squareWidth * squareHeight;

	for(; ptr < end; ++ptr)
		*ptr = BlockMkr::GetRandomBlock();
}

void Field::GetFallingInfo(int& x, int& y, int& color) const
{
	x = fallingX;
	y = fallingY;
	color = fallingColor;
}
