#include "SFComboBox.h"

SFComboBox::SFComboBox(SFWidget* widget)
{
	parentHandle = widget->getWidgetHandle();
}

SFComboBox::~SFComboBox()
{
}

VOID SFComboBox::Show(int value)
{
	handle = CreateWindow("COMBOBOX", getText().c_str(),
		WS_CHILD | WS_VISIBLE | CBS_SORT | CBS_DROPDOWNLIST,
	getXPos(), getYPos(), getWidth(), getHeight(), // Измени размер на 500
		parentHandle, 0, GetModuleHandle(0), 0);
}

VOID SFComboBox::addItem(std::string itemText)
{
	static UINT i = 0;
	i++;

	indexes[i] = itemText;

	SendMessage(handle, CB_ADDSTRING, 0, (LPARAM) itemText.c_str());
}

std::string SFComboBox::getItemText(UINT index)
{
	return indexes[index];
}