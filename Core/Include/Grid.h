#pragma once

namespace Core {

class Grid
{
	int* gridPtr;
	int sizeX, sizeY;

	public:
	Grid();
	~Grid();
	void Create(int sizeX, int sizeY);
	void Destroy();
	int GetSizeX() const;
	int GetSizeY() const;
	int const * GetReadPtr() const;
	int const * GetReadRowPtr(int y) const;
	int * GetWritePtr();
	int * GetWriteRowPtr(int y);
	int Get(int x, int y) const;
	void Set(int x, int y, int value);
};

}
