#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "KirbyCore.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	GameStart();
	GameStop();
	return 0;
}