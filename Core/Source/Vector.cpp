#pragma once
#include "../Include/Vector.h"
#include "../Include/VectorImpl.h"

using namespace Core;

template<class T> Vector<T>::~Vector(){}

template<class T> Vector<T>* Vector<T>::Create()
{
	return new VectorImpl<T>();
}
