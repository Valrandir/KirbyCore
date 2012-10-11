#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "WindowBase.h"

using namespace Core;

class WindowBaseImpl : public WindowBase
{
	static WNDCLASSEX CreateWindowClass(HINSTANCE hInstance);
	static void AdjustWindowRect(int &width, int &height, DWORD style);
	static void CenterWindowPos(int &x, int &y, int width, int height);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
	HWND hWnd;
	int width, height;
	int clientWidth, clientHeight;

	virtual LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	public:
	WindowBaseImpl(CORECSTR title, int clientWidth, int clientHeight);
	~WindowBaseImpl();
	void Show() const;
	bool Update() const;
	void GetSize(int& width, int& height) const;
	void GetClientSize(int& clientWidth, int& clientHeight) const;
};
