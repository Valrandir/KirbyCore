#include "StackTrace.h"
#include "WindowGDI.h"

using namespace Core::StackTrace;
using namespace Core::Window;

WNDCLASSEX WindowGDI::RegisterClassEx(HINSTANCE hInstance)
{
	StackLog;
	WNDCLASSEX wc = {0};

	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = WndProc;
	wc.cbWndExtra = sizeof(WindowGDI*);
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = TEXT("CoreWindowGDI");

	Try(::RegisterClassEx(&wc));

	return wc;
}

void WindowGDI::AdjustWindowRect(int &width, int &height, DWORD style)
{
	StackLog;
	RECT rect = {0, 0, width, height};
	Try(::AdjustWindowRect(&rect, style, FALSE));
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
}

void WindowGDI::CenterWindowPos(int &x, int &y, int width, int height)
{
	x = (GetSystemMetrics(SM_CXSCREEN) - width) >> 1;
	y = (GetSystemMetrics(SM_CYSCREEN) - height) >> 1;
}

LRESULT CALLBACK WindowGDI::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	StackLog;

	switch(msg)
	{
		case WM_KEYDOWN:
			if(wParam == VK_ESCAPE)
				PostQuitMessage(0);
			break;
		case WM_PAINT:
			((WindowGDI*)GetWindowLong(hWnd, GWL_USERDATA))->OnPaint();
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

void WindowGDI::SetUserData()
{
	StackLog;
	LONG result;
	SetLastError(0);
	result = ::SetWindowLong(hWnd, GWL_USERDATA, (LONG)this);
	Try(!result && GetLastError() == 0)
}

void WindowGDI::SetupBackBuffer()
{
	StackLog;
	HDC hDC;
	Try(hBrush_DC_BRUSH = (HBRUSH)GetStockObject(DC_BRUSH));
	Try(hDC = GetDC(hWnd));
	Try(hBufferDC = CreateCompatibleDC(hDC));
	Try(hBufferBitmap = CreateCompatibleBitmap(hDC, width, height));
	SelectObject(hBufferDC, hBufferBitmap);
	SelectObject(hBufferDC, hBrush_DC_BRUSH);
	Try(ReleaseDC(hWnd, hDC));
}

void WindowGDI::ClearBackBuffer(HBRUSH hBrush)
{
	StackLog;
	RECT rect = {0, 0, width, height};
	Try(::FillRect(hBufferDC, &rect, hBrush));
}

void WindowGDI::OnPaint() const
{
	StackLog;
	PAINTSTRUCT ps;
	int x, y, cx, cy;

	Try(BeginPaint(hWnd, &ps));

	x = ps.rcPaint.left;
	y = ps.rcPaint.top;
	cx = ps.rcPaint.right - x;
	cy = ps.rcPaint.bottom - y;

	//Unlike stated in the msdn documentation BitBlt always returns 0
	BitBlt(ps.hdc, x, y, cx, cy, hBufferDC, x, y, SRCCOPY);

	EndPaint(hWnd, &ps);
}

WindowGDI::WindowGDI(LPCTSTR caption, int width, int height) : width(width), height(height), hBufferDC(NULL), hBufferBitmap(NULL)
{
	WNDCLASSEX wc;
	DWORD wndStyle;
	int x, y;

	hInstance = (HINSTANCE)GetModuleHandle(NULL);

	wc = RegisterClassEx(hInstance);
	wndStyle = WS_POPUP | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER;
	AdjustWindowRect(width, height, wndStyle);
	CenterWindowPos(x, y, width, height);

	Try(hWnd = CreateWindowEx(0, wc.lpszClassName, caption, wndStyle, x, y, width, height, HWND_DESKTOP, NULL, hInstance, NULL));
	SetUserData();

	SetupBackBuffer();
	ClearBackBuffer((HBRUSH)GetSysColorBrush(COLOR_3DFACE));

	ShowWindow(hWnd, SW_SHOW);
}

WindowGDI::~WindowGDI()
{
	if(hBufferBitmap)
	{
		DeleteObject(hBufferBitmap);
		hBufferBitmap = NULL;
	}

	if(hBufferDC)
	{
		ReleaseDC(hWnd, hBufferDC);
		hBufferDC = NULL;
	}
}

BOOL WindowGDI::Refresh() const
{
	MSG msg;

	while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if(msg.message == WM_QUIT)
			return FALSE;
	}

	return TRUE;
}

void WindowGDI::Quit() const
{
	PostQuitMessage(0);
}

int WindowGDI::GetWidth() const
{
	return width;
}

int WindowGDI::GetHeight() const
{
	return height;
}

void WindowGDI::FillRect(int x, int y, int width, int height, COLORREF color)
{
	RECT rect = {x, y, width, height};
	SetDCBrushColor(hBufferDC, color);
	::FillRect(hBufferDC, &rect, hBrush_DC_BRUSH);
}

void WindowGDI::Rectangle(int x, int y, int width, int height, COLORREF color)
{
	SetDCBrushColor(hBufferDC, color);
	::Rectangle(hBufferDC, x, y, width, height);
}
