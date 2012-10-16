#pragma once

#include "Vector.h"

#ifndef CORE_NOMAIN
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>

	//extern int CoreMain();

	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
	{

auto v = Core::Vector<int>::Create();
v->Push(1);
v->Push(2);
v->Push(3);
v->Push(4);
v->Push(5);

auto a = v->Begin();
int* b = v->Begin();

int z;
for(auto it = v->Begin(); it < v->End(); ++it)
	z = *it;

		//return CoreMain();
		return 0;
	}
#endif
