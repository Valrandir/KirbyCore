#include "stdlib.h"
#include "StackTrace.h"
#include "Grid.h"

#define GridFinalErrorM FinalErrorM(TEXT("Invalid Coordinates"))

using namespace Core;
using namespace Core::StackTrace;

Grid::Grid() : gridPtr(0), size(0), sizeX(0), sizeY(0), byteSize(0) {}

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
	if(gridPtr)
	{
		free(gridPtr);
		gridPtr = 0;
		size = 0;
		sizeX = 0;
		sizeY = 0;
		byteSize = 0;
	}
}

void Grid::GetSize(int& x, int& y) const
{
	x = sizeX;
	y = sizeY;
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
	if(y < 0 || y >= sizeY)
		GridFinalErrorM;

	if(begin) *begin = gridPtr + y;
	if(end) *end = gridPtr + y + sizeY;
	if(count) *count = sizeY;
}

int Grid::Get(int x, int y) const
{
	if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
		return *(gridPtr + y * sizeX + x);
	return 0;
}

void Grid::Set(int x, int y, int value)
{
	if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
		*(gridPtr + y * sizeX + x) = value;
}
