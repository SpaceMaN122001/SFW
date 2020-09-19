#include "SFEditBox.h"

SFEditBox::SFEditBox(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFEditBox::~SFEditBox()
{
}

VOID SFEditBox::Show(int value)
{
	handle = CreateWindow(
		"EDIT",
		getText().c_str(),
		WS_CHILD | WS_VISIBLE | WS_VSCROLL |
		ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
		getXPos(),
		getYPos(),
		getWidth(),
		getHeight(),
		parentHandle,
		NULL,
		(HINSTANCE)GetWindowLong(parentHandle, GWL_HINSTANCE),
		NULL);
}