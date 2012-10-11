#include "../Include/Window2DImpl.h"

void Window2DImpl::SetupBackBuffer()
{
	HDC hDC;
	hDC_BRUSH = (HBRUSH)GetStockObject(DC_BRUSH);
	hDC = GetDC(hWnd);
	hBufferDC = CreateCompatibleDC(hDC);
	hBufferBitmap = CreateCompatibleBitmap(hDC, clientWidth, clientHeight);
	SelectObject(hBufferDC, hBufferBitmap);
	SelectObject(hBufferDC, hDC_BRUSH);
	ReleaseDC(hWnd, hDC);
	Clear();
}

void Window2DImpl::OnPaint() const
{
	PAINTSTRUCT ps;
	int x, y, cx, cy;

	BeginPaint(hWnd, &ps);

	x = ps.rcPaint.left;
	y = ps.rcPaint.top;
	cx = ps.rcPaint.right - x;
	cy = ps.rcPaint.bottom - y;

	BitBlt(ps.hdc, x, y, cx, cy, hBufferDC, x, y, SRCCOPY);

	EndPaint(hWnd, &ps);
}

LRESULT Window2DImpl::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_PAINT:
			OnPaint();
			break;
		default:
			return WindowBaseImpl::WindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

Window2DImpl::Window2DImpl(CORESTR title, int clientWidth, int clientHeight) : WindowBaseImpl(title, clientWidth, clientHeight)
{
	SetupBackBuffer();
}

Window2DImpl::~Window2DImpl()
{
}

void Window2DImpl::Show() const
{
	WindowBaseImpl::Show();
}

bool Window2DImpl::Update() const
{
	return WindowBaseImpl::Update();
}

void Window2DImpl::GetSize(int& width, int& height) const
{
	WindowBaseImpl::GetSize(width, height);
}

void Window2DImpl::GetClientSize(int& clientWidth, int& clientHeight) const
{
	WindowBaseImpl::GetClientSize(clientWidth, clientHeight);
}

void Window2DImpl::Clear() const
{
	HBRUSH hBrush = (HBRUSH)GetSysColorBrush(COLOR_3DFACE);
	RECT rect = {0, 0, clientWidth, clientHeight};
	FillRect(hBufferDC, &rect, hBrush);
	InvalidateRect(hWnd, 0, 0);
}

void Window2DImpl::DrawRect(int x, int y, int width, int height, unsigned int color) const
{
	RECT rect = {x, y, x + width, y + height};
	SetDCBrushColor(hBufferDC, color);
	::FillRect(hBufferDC, &rect, hDC_BRUSH);
}

void Window2DImpl::DrawLine(int x, int y, int x2, int y2) const
{
	MoveToEx(hBufferDC, x, y, 0);
	LineTo(hBufferDC, x2, y2);
}

/*
void Window2DImpl::DrawText(CORESTR text, int len, int x, int y) const
{
	TextOut(hBufferDC, x, y, text, len);
}
*/
