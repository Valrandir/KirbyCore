#include "stdlib.h"
#include "StackTrace.h"
#include "Grid.h"

using namespace Core;
using namespace Core::StackTrace;

#define GridFinalErrorM FinalErrorM(TEXT("Invalid Coordinates"))

Grid::Grid() : sizeX(0), sizeY(0), gridPtr(0) {}

Grid::~Grid()
{
	Destroy();
}

void Grid::Create(int sizeX, int sizeY)
{
	StackLog;
	Destroy();

	Try(gridPtr = (int*)malloc(sizeof(int*) * sizeX * sizeY));

	if(gridPtr)
	{
		this->sizeX = sizeX;
		this->sizeY = sizeY;
	}
}

void Grid::Destroy()
{
	sizeX = 0;
	sizeY = 0;
	if(gridPtr)
	{
		free(gridPtr);
		gridPtr = 0;
	}
}

int Grid::GetSizeX() const
{
	return sizeX;
}

int Grid::GetSizeY() const
{
	return sizeY;
}

int const * Grid::GetReadPtr() const
{
	return gridPtr;
}

int const * Grid::GetReadRowPtr(int y) const
{
	StackLog;

	if(y >= 0 && y < sizeY)
		return gridPtr + y * sizeX;

	GridFinalErrorM;
	return 0;
}

int * Grid::GetWritePtr()
{
	return gridPtr;
}

int * Grid::GetWriteRowPtr(int y)
{
	StackLog;

	if(y >= 0 && y < sizeY)
		return gridPtr + y * sizeX;

	GridFinalErrorM;
	return 0;
}

int Grid::Get(int x, int y) const
{
	StackLog;

	if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
		return *(gridPtr + y * sizeX + x);

	GridFinalErrorM;
	return 0;
}

void Grid::Set(int x, int y, int value)
{
	StackLog;

	if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
		*(gridPtr + y * sizeX + x) = value;
	else
		GridFinalErrorM;
}
