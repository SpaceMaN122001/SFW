#include "SFListBox.h"

SFListBox::SFListBox(SFWidget* widget)
{
	parentHandle = widget->getWidgetHandle();
}

SFListBox::~SFListBox()
{
}

VOID SFListBox::Show(int value)
{
	ID = getUniqueID();

	handle = CreateWindow("listbox", NULL,
		WS_CHILD | WS_VISIBLE | LBS_STANDARD |
		LBS_WANTKEYBOARDINPUT,
		getXPos(), getYPos(), getWidth(), getHeight(),
		parentHandle, (HMENU)ID, GetModuleHandle(0), NULL);
}

VOID SFListBox::addItem(std::string itemText)
{
	static UINT i = 0;
	i++;

	indexes[i] = itemText;

	SendMessage(handle, LB_ADDSTRING, 0, (LPARAM)itemText.c_str());
}

std::string SFListBox::getItemText(UINT index)
{
	return indexes[index];
}