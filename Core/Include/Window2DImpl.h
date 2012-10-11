#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "Window2D.h"
#include "WindowBaseImpl.h"

using namespace Core;

class Window2DImpl : public Window2D, private WindowBaseImpl
{
	HDC hBufferDC;
	HBITMAP hBufferBitmap;
	HBRUSH hDC_BRUSH;

	void SetupBackBuffer();
	void OnPaint() const;
	LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	public:
	Window2DImpl(CORECSTR title, int clientWidth, int clientHeight);
	~Window2DImpl();

	//WindowBase
	void Show() const;
	bool Update() const;
	void GetSize(int& width, int& height) const;
	void GetClientSize(int& clientWidth, int& clientHeight) const;

	//Window2D
	void Clear() const;
	void DrawRect(int x, int y, int width, int height, unsigned int color) const;
	void DrawLine(int x, int y, int x2, int y2) const;
	void DrawString(CORECSTR text, int x, int y) const;
};
