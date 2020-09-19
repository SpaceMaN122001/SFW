#pragma once
#define SNULL ""
#define repaint Show

#include <Windows.h>
#include <string>
#include <sstream>
#include <CommCtrl.h>
#include "SFColor.h"

extern UINT getUniqueID();
extern std::string convertToString(int value);
extern std::string convertToString(double value);
extern std::string convertToString(float value);
extern std::string convertToString(long value);
extern std::string convertToString(UINT value);

enum ScreenMode
{
	Hide = 0,
	Normal = 1,
	Minimized = 2,
	Maximized = 3
};

struct FontAttributes
{
	BOOL fontWeightItalics;
	BOOL fontUnderLine;
	BOOL fontStrikeOut;
	std::string fontName;

	FontAttributes()
	{
		fontWeightItalics = FALSE;
		fontUnderLine = FALSE;
		fontStrikeOut = FALSE;
		fontName = "Arial";
	}
};

enum State
{
	Checked = 0x0001,
	UnChecked = 0x0000
};

class SFWidget
{
public:
	HWND getWidgetHandle();
	virtual VOID Show(int value = 1);
	VOID setPosition(int x, int y);
	VOID setBackgroundColor(int r, int g, int b);
	VOID setSize(UINT w, UINT h);
	VOID setText(std::string text);
	VOID setWeigthItalics();
	VOID setUnderLine();
	VOID setStrikeOut();
	VOID setFont(std::string fontName = SNULL);
	VOID setFixedSize();
	VOID setBorderStyle() { _borderStyle = WS_CHILDWINDOW | WS_VISIBLE | WS_OVERLAPPEDWINDOW; }
	VOID setToolTip(char text[260]);
	VOID Disable(bool value);
	VOID close();
	UINT getXPos() const { return _xPos; }
	UINT getYPos() const { return _yPos; }
	UINT getWidgetID() const { if (this == NULL) return NULL; return ID; }
	UINT getWidth() const { return _width; }
	UINT getHeight() const { return _height; }
	std::string getText() const { return _text; }
	LONG getBorderStyle() const { return _borderStyle; }
	HBRUSH getBackgroundColor() const { return _backColor; }
	UINT getCurrentWidth();
	UINT getCurrentHeight();
	VOID setState(INT state) { SendMessage(handle, BM_SETCHECK, state, 0); _state = state; }
	INT getState() const { return _state; }
	VOID setFocus() { SetFocus(handle); }
	VOID setStyle(INT style) { _style = style; }
	INT getStyle() const { return _style; }
protected:
	HWND handle;
	HWND parentHandle;
	UINT ID;
private:
	INT _xPos = CW_USEDEFAULT;
	INT _yPos = NULL;
	std::string _text = "SFW";
	UINT _width = CW_USEDEFAULT;
	UINT _height = NULL;
	FontAttributes _font;
	LONG _borderStyle = WS_OVERLAPPEDWINDOW;
	HBRUSH _backColor = (HBRUSH)GetStockObject(WHITE_BRUSH);
	INT _state;
	INT _style;
};

