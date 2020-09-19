#pragma once
#include "SFWidgets.h"

class Window1Form
{
public:
	SFPushButton* bt;
	SFCheckBox* check;

	VOID setupUi(SFWidget* window)
	{
		bt = new SFPushButton(window);
		bt->setPosition(0, 0);
		bt->setSize(70, 30);
		bt->Show();
	}
};