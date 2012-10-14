#pragma once
#include "../Include/VectorImpl.h"

template<class T> VectorImpl<T>::~VectorImpl()
{
}

template<class T> void VectorImpl<T>::Reserve(int size)
{
	vec.reserve(size);
}

template<class T> void VectorImpl<T>::Push(T val)
{
	vec.push_back(val);
}

template<class T> void VectorImpl<T>::Pop()
{
	vec.pop_back();
}

template<class T> void VectorImpl<T>::Clear()
{
	vec.clear();
}

template<class T> T* VectorImpl<T>::Begin()
{
	return &(*vec.begin());
}

template<class T> T* VectorImpl<T>::End()
{
	return &(*vec.end());
}

template<class T> int VectorImpl<T>::Length() const
{
	return vec.size();
}
