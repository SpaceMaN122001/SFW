#include "SFRadioButton.h"

SFRadioButton::SFRadioButton(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFRadioButton::~SFRadioButton()
{
}

VOID SFRadioButton::Show(int value)
{
	handle = CreateWindow("button", getText().c_str(),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		getXPos(), getYPos(), getWidth(), getHeight(), parentHandle, (HMENU)getUniqueID(), GetModuleHandle(0), NULL);
}