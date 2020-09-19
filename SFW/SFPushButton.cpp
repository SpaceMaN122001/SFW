#include "SFPushButton.h"

SFPushButton::SFPushButton(SFWidget* window, std::string text, INT x, INT y, UINT width, UINT heigth)
{
    parentHandle = window->getWidgetHandle();

	setPosition(x, y);
	setSize(width, heigth);
	setText(text);
}

SFPushButton::~SFPushButton()
{
}

VOID SFPushButton::Show(int value)
{
    ID = getUniqueID();

    handle = CreateWindow(
        "BUTTON",  // Predefined class; Unicode assumed 
        getText().c_str(),      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_FLAT,  // Styles 
        getXPos(),         // x position 
        getYPos(),         // y position 
        getWidth(),        // Button width
        getHeight(),        // Button height
        parentHandle,     // Parent window
        (HMENU)ID,       // No menu.
        (HINSTANCE)GetWindowLongPtr(parentHandle, GWLP_HINSTANCE),
        NULL);

	setFont();

	/*HFONT hfont = CreateFont(-13,
		0,
		0,
		0,
		FW_NORMAL,
		FALSE,
		FALSE,
		FALSE,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		"Arial"
	);
	SendMessage(handle, WM_SETFONT, (WPARAM)hfont, TRUE);*/
}