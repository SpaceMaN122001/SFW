#include "SFCheckBox.h"

SFCheckBox::SFCheckBox(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFCheckBox::~SFCheckBox()
{
}

VOID SFCheckBox::Show(int value)
{
	handle = CreateWindow(
		"button",
		getText().c_str(),
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		getXPos(),
		getYPos(),
		getWidth(),
		getHeight(),
		parentHandle,
		(HMENU)getUniqueID(),
		GetModuleHandle(0),
		NULL
	);
}