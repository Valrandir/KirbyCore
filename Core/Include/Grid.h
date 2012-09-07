#pragma once

namespace Core {

class Grid
{
	int* gridPtr;
	int size, sizeX, sizeY;
	int byteSize;

	public:
	Grid();
	~Grid();
	void Create(int sizeX, int sizeY);
	void Clear(int val);
	void Destroy();
	void GetSize(int& x, int& y) const;
	int GetSizeX() const;
	int GetSizeY() const;
	void GetReadPtr(int const **begin, int const **end, int *count) const;
	void GetReadRowPtr(int y, int const **begin, int const **end, int *count) const;
	void GetWritePtr(int **begin, int const **end, int *count);
	void GetWriteRowPtr(int y, int **begin, int const **end, int *count);
	int Get(int x, int y) const;
	void Set(int x, int y, int value);
};

}
