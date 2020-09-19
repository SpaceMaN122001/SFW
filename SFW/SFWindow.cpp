//#include "SFWindow.h"
//
//SFWindow::SFWindow()
//{
//}
//
//VOID SFWindow::Initial(WNDPROC wnd)
//{
//	WNDCLASSEX wndclass;
//	wndclass.cbSize = sizeof(wndclass);
//	wndclass.style = CS_HREDRAW | CS_VREDRAW;
//	wndclass.lpfnWndProc = wnd;
//	wndclass.cbClsExtra = 0;
//	wndclass.cbWndExtra = 0;
//	wndclass.hInstance = GetModuleHandle(0);
//	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wndclass.hbrBackground = (HBRUSH)getBackgroundColor();
//	//wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	wndclass.lpszMenuName = NULL;
//	wndclass.lpszClassName = "Window";
//	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//
//	RegisterClassEx(&wndclass);
//
//	handle = CreateWindow(
//		"Window",
//		getText().c_str(),
//		getBorderStyle(),
//		getXPos(),
//		getYPos(),
//		getWidth(),
//		getHeight(),
//		NULL,
//		NULL,
//		GetModuleHandle(0),
//		this);
//}
//
//VOID SFWindow::Show(int value)
//{
//	ShowWindow(handle, value);
//	UpdateWindow(handle);
//}
//
//SFWindow::~SFWindow()
//{
//}
//
//LRESULT SFWindow::WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
//{
//	switch (Message)
//	{
//	case WM_KEYDOWN:
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, Message, wparam, lparam);
//	}
//	return 0;
//}