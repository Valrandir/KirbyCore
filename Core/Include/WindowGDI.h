#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace Core { namespace Window {

class __declspec(dllexport) WindowGDI
{
	protected:
	HINSTANCE hInstance;
	HWND hWnd;
	int width, height;
	HDC hBufferDC;
	HBITMAP hBufferBitmap;
	HBRUSH hBrush_DC_BRUSH;

	static WNDCLASSEX RegisterClassEx(HINSTANCE hInstance);
	static void AdjustWindowRect(int &width, int &height, DWORD style);
	static void CenterWindowPos(int &x, int &y, int width, int height);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void SetUserData();
	void SetupBackBuffer();
	void OnPaint() const;

	public:
	WindowGDI(LPCTSTR caption, int width, int height);
	~WindowGDI();
	BOOL Refresh() const;
	void Quit() const;
	int GetWidth() const;
	int GetHeight() const;
	void ClearBackBuffer();
	void ClearBackBuffer(HBRUSH hBrush);
	void ClearBackBuffer(COLORREF color);
	void FillRect(int x, int y, int width, int height, COLORREF color);
	void Rectangle(int x, int y, int width, int height, COLORREF color);
	void Line(int x, int y, int x2, int y2);
};

} }
