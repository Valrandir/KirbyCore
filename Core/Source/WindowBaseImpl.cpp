#include "../Include/WindowBaseImpl.h"

WNDCLASSEX WindowBaseImpl::CreateWindowClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc = {0};

	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = WndProc;
	wc.cbWndExtra = sizeof(WindowBaseImpl*);
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = TEXT("WindowBase");

	RegisterClassEx(&wc);

	return wc;
}

void WindowBaseImpl::AdjustWindowRect(int &width, int &height, DWORD style)
{
	RECT rect = {0, 0, width, height};
	::AdjustWindowRect(&rect, style, FALSE);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
}

void WindowBaseImpl::CenterWindowPos(int &x, int &y, int width, int height)
{
	x = (GetSystemMetrics(SM_CXSCREEN) - width) >> 1;
	y = (GetSystemMetrics(SM_CYSCREEN) - height) >> 1;
}

LRESULT CALLBACK WindowBaseImpl::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(auto instance = (WindowBaseImpl*)GetWindowLong(hWnd, GWL_USERDATA))
		return instance->WindowProc(hWnd, msg, wParam, lParam);
	else
		return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT WindowBaseImpl::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

WindowBaseImpl::WindowBaseImpl(CORECSTR title, int clientWidth, int clientHeight) : width(clientWidth), height(clientHeight), clientWidth(clientWidth), clientHeight(clientHeight)
{
	HINSTANCE hInstance;
	WNDCLASSEX wc;
	DWORD wndStyle;
	int x, y;

	hInstance = (HINSTANCE)GetModuleHandle(NULL);
	wc = CreateWindowClass(hInstance);
	wndStyle = WS_POPUP | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER;
	AdjustWindowRect(width, height, wndStyle);
	CenterWindowPos(x, y, width, height);

	hWnd = CreateWindowEx(0, wc.lpszClassName, (LPCTSTR)title, wndStyle, x, y, width, height, HWND_DESKTOP, NULL, hInstance, NULL);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)this);
}

WindowBaseImpl::~WindowBaseImpl()
{
}

void WindowBaseImpl::Show() const 
{
	ShowWindow(hWnd, SW_SHOW);
}

bool WindowBaseImpl::Update() const
{
	MSG msg;

	while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		DispatchMessage(&msg);
		if(msg.message == WM_QUIT)
			return false;
	}

	return true;
}

void WindowBaseImpl::GetSize(int& width, int& height) const
{
	width = this->width;
	height = this->height;
}

void WindowBaseImpl::GetClientSize(int& clientWidth, int& clientHeight) const
{
	clientWidth = this->clientWidth;
	clientHeight = this->clientHeight;
}
