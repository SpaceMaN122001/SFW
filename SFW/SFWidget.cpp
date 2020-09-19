#include "SFWidget.h"

HWND SFWidget::getWidgetHandle()
{
	if (this == NULL) return NULL;

	return handle;
}

VOID SFWidget::Show(int value)
{
}

VOID SFWidget::setPosition(int x, int y)
{
	_xPos = x;
	_yPos = y;
}

VOID SFWidget::setBackgroundColor(int r, int g, int b)
{
	_backColor = CreateSolidBrush(RGB(r, g, b));
}

VOID SFWidget::setSize(UINT w, UINT h)
{
	_width = w;
	_height = h;
}

VOID SFWidget::setText(std::string text)
{
	_text = text;
}

VOID SFWidget::setWeigthItalics()
{
	_font.fontWeightItalics = TRUE;
}

VOID SFWidget::setUnderLine()
{
	_font.fontUnderLine = TRUE;
}

VOID SFWidget::setStrikeOut()
{
	_font.fontStrikeOut = TRUE;
}

VOID SFWidget::setFont(std::string fontName)
{
	if(fontName != SNULL) _font.fontName = fontName;

	HFONT hfont = CreateFont(-13,
		0,
		0,
		0,
		FW_NORMAL,
		_font.fontWeightItalics,
		_font.fontUnderLine,
		_font.fontStrikeOut,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		_font.fontName.c_str()
	);
	SendMessage(handle, WM_SETFONT, (WPARAM)hfont, TRUE);
}

VOID SFWidget::setFixedSize()
{
	_borderStyle = WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE;
}

VOID SFWidget::Disable(bool value)
{
	EnableWindow(handle, value);
}

VOID SFWidget::setToolTip(char text[260])
{
	HWND hwndTT = CreateWindowEx(WS_EX_TOPMOST, TOOLTIPS_CLASS, NULL,
		WS_POPUP | TTS_NOPREFIX | TTS_ALWAYSTIP, 0, 0, 0, 0, handle, NULL, 0, NULL);


	TTTOOLINFO ti = { 0 };
	ti.cbSize = sizeof(TTTOOLINFO);
	ti.uFlags = TTF_SUBCLASS;
	ti.hwnd = handle;
	ti.lpszText = text;
	GetClientRect(handle, &ti.rect);

	if (!SendMessage(hwndTT, TTM_ADDTOOL, 0, (LPARAM)&ti))
		MessageBox(0, TEXT("Failed: TTM_ADDTOOL"), 0, 0);
}

VOID SFWidget::close()
{
	CloseWindow(handle);
}

UINT SFWidget::getCurrentWidth()
{
	RECT rect;
	GetClientRect(handle, &rect);
	UINT w = rect.right - rect.left;

	return w;
}

UINT SFWidget::getCurrentHeight()
{
	RECT rect;
	GetClientRect(handle, &rect);
	UINT h = rect.bottom = rect.top;

	return h;
}

UINT getUniqueID()
{
	static int j = 0;
	j++;

	return j;
}

std::string convertToString(int value)
{
	std::stringstream ss;
	ss << value;
	std::string str = ss.str();

	return str;
}

std::string convertToString(double value)
{
	std::stringstream ss;
	ss << value;
	std::string str = ss.str();

	return str;
}

std::string convertToString(float value)
{
	std::stringstream ss;
	ss << value;
	std::string str = ss.str();

	return str;
}

std::string convertToString(long value)
{
	std::stringstream ss;
	ss << value;
	std::string str = ss.str();

	return str;
}

std::string convertToString(UINT value)
{
	std::stringstream ss;
	ss << value;
	std::string str = ss.str();

	return str;
}