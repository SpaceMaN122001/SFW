#pragma once
#define processingMessages LRESULT WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
#define defaultMessageHandling DefWindowProc(hwnd, Message, wParam, lParam)

#include "SFWidget.h"
#include <vector>

class SFWindow : public SFWidget
{
public:
	SFWindow()
	{
	}
	~SFWindow()
	{
	}
	VOID Initial(WNDPROC wnd = WndProc)
	{
		WNDCLASSEX wndclass;
		wndclass.cbSize = sizeof(wndclass);
		wndclass.style = CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = wnd;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = GetModuleHandle(0);
		wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.hbrBackground = (HBRUSH)getBackgroundColor();
		//wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = "Window";
		wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		RegisterClassEx(&wndclass);

		handle = CreateWindow(
			"Window",
			getText().c_str(),
			getBorderStyle(),
			getXPos(),
			getYPos(),
			getWidth(),
			getHeight(),
			NULL,
			NULL,
			GetModuleHandle(0),
			this);
	}
	virtual VOID Show(int value = 1) override
	{
		ShowWindow(handle, value);
		UpdateWindow(handle);
	}
	template<typename T>
	static T* setWindowLong(HWND hwnd, LPARAM lParam)
	{
		T* wnd = NULL;

		wnd = (T*)LPCREATESTRUCT(lParam)->lpCreateParams;
		SetWindowLong(hwnd, GWL_USERDATA, LONG(LPCREATESTRUCT(lParam)->lpCreateParams));

		return wnd;
	}
	template<typename T>
	static T* getWindowLong(T* window, HWND hwnd)
	{
		window = (T*)GetWindowLong(hwnd, GWL_USERDATA);

		return window;
	}
private:
	static LRESULT WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
	{
		SFWindow* wnd = 0;

		if (Message == WM_NCCREATE)
		{

			wnd = (SFWindow*)LPCREATESTRUCT(lparam)->lpCreateParams;

			SetWindowLong(hwnd, GWL_USERDATA, LONG(LPCREATESTRUCT(lparam)->lpCreateParams));

		}

		wnd = (SFWindow*)GetWindowLong(hwnd, GWL_USERDATA);

		switch (Message)
		{
		case WM_KEYDOWN:
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, Message, wparam, lparam);
		}
		return 0;
	}
};
