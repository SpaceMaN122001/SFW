#include "SFApplication.h"

VOID SFApplication::Exec()
{
	HWND myConsole = GetConsoleWindow();
	ShowWindow(myConsole, 0);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

VOID SFApplication::Quit()
{
	PostQuitMessage(0);
}