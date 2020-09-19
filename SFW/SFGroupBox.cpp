#include "SFGroupBox.h"

SFGroupBox::SFGroupBox(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFGroupBox::~SFGroupBox()
{
}

VOID SFGroupBox::Show(int value)
{
	handle = CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed 
		getText().c_str(),      // Button text 
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,  // Styles 
		getXPos(),         // x position 
		getYPos(),         // y position 
		getWidth(),        // Button width
		getHeight(),        // Button height
		parentHandle,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLongPtr(parentHandle, GWLP_HINSTANCE),
		NULL);
}