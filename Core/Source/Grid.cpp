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

	size = sizeX * sizeY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	byteSize = sizeof(int) * sizeX * sizeY;

	Try(gridPtr = (int*)malloc(byteSize));
	Clear(0);
}

void Grid::Clear(int val)
{
	memset(gridPtr, val, byteSize);
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

void Grid::GetReadPtr(int const **begin, int const **end, int *count) const
{
	if(begin) *begin = gridPtr;
	if(end) *end = gridPtr + size;
	if(count) *count = size;
}

void Grid::GetReadRowPtr(int y, int const **begin, int const **end, int *count) const
{
	StackLog;

	if(y < 0 || y >= sizeY)
		GridFinalErrorM;

	if(begin) *begin = gridPtr + y;
	if(end) *end = gridPtr + y + sizeY;
	if(count) *count = sizeY;
}

void Grid::GetWritePtr(int **begin, int const **end, int *count)
{
	if(begin) *begin = gridPtr;
	if(end) *end = gridPtr + size;
	if(count) *count = size;
}

void Grid::GetWriteRowPtr(int y, int **begin, int const **end, int *count)
{
	StackLog;

	if(y < 0 || y >= sizeY)
		GridFinalErrorM;

	if(begin) *begin = gridPtr + y;
	if(end) *end = gridPtr + y + sizeY;
	if(count) *count = sizeY;
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
