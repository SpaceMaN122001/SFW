#include "SFProgressBar.h"

SFProgressBar::SFProgressBar(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFProgressBar::~SFProgressBar()
{
}

VOID SFProgressBar::Show(int value)
{
	handle = CreateWindowEx(0, PROGRESS_CLASS, getText().c_str(),
		WS_CHILD | WS_VISIBLE + _style, getXPos(),
		getYPos(),
		getWidth(), getHeight(),
		parentHandle, (HMENU)0, GetModuleHandle(0), NULL);

	SendMessage(handle, PBM_SETRANGE, 0, MAKELPARAM(_minValue, _maxValue));

	//SendMessage(handle, (UINT)PBM_SETBARCOLOR, 0, (LPARAM)RGB(0, 170, 0));
	SendMessage(handle, (UINT)PBM_SETBARCOLOR, 0, _lineColor);
}

VOID SFProgressBar::setValue(int value)
{
	SendMessage(handle, PBM_SETPOS, value, 0);
}

VOID SFProgressBar::setMaxValue(int value)
{
	_maxValue = value;
}

VOID SFProgressBar::setMinValue(int value)
{
	_minValue = value;
}

VOID SFProgressBar::setStyle(int value)
{
	_style = value;
}

VOID SFProgressBar::setLineColor(int r, int g, int b)
{
	_lineColor = (LPARAM)RGB(r, g, b);
}

VOID SFProgressBar::setLineColor(LPARAM color)
{
	_lineColor = color;
}