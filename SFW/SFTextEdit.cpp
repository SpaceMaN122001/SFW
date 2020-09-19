#include "SFTextEdit.h"

SFTextEdit::SFTextEdit(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFTextEdit::~SFTextEdit()
{
}

VOID SFTextEdit::Show(int value)
{
	UINT ID = getUniqueID();

	handle = CreateWindowEx(
		0, "EDIT",   // predefined class 
		NULL,         // no window title 
		WS_CHILD | WS_VISIBLE | WS_VSCROLL |
		ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
		getXPos(), getYPos(), getWidth(), getHeight(),   // set size in WM_SIZE message 
		parentHandle,         // parent window 
		(HMENU)ID,   // edit control ID 
		(HINSTANCE)GetWindowLongPtr(parentHandle, GWLP_HINSTANCE),
		NULL);
}

std::string SFTextEdit::getText()
{
	char buff[1024];

	GetWindowText(handle, buff, 1024);

	std::string s1 = "";

	for (char s : buff) {

		s1 += s;
	}

	return s1;
}

VOID SFTextEdit::setText(std::string text)
{
	SendMessage(handle, WM_SETTEXT, 0, (LPARAM)text.c_str());
}