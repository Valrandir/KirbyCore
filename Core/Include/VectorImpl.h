#pragma once
#include <vector>
#include "../Include/Vector.h"

template<class T> class VectorImpl : public Core::Vector<T>
{
	protected:
	std::vector<T> vec;

	public:
	~VectorImpl();
	void Reserve(int size);
	void Push(T val);
	void Pop();
	void Clear();
	T* Begin();
	T* End();
	int Length() const;
};

//Template need definition to be available within the same compilation unit
#include "../Source/VectorImpl.cpp"
