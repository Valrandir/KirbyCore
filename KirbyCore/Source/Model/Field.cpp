#include "Field.h"

Field::Field()
{
	squareWidth = 10;
	squareHeight = 30;

	Grid::Create(squareWidth, squareHeight);
	Set(5, 5, RGB(255, 0, 0));
}
