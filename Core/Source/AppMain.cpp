#pragma once

#ifndef CORE_NOMAIN
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>

	extern int CoreMain();

	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
	{
		return CoreMain();
	}
#endif