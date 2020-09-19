#pragma once
#include "SFWidget.h"

class SFSlider : public SFWidget
{
public:
	SFSlider(SFWidget* window)
	{
		parentHandle = window->getWidgetHandle();

		setStyle(WS_CHILD | WS_VISIBLE | TBS_ENABLESELRANGE);
	}
	~SFSlider()
	{
	}
	virtual VOID Show(int value = 1) override
	{
		ID = getUniqueID();


		handle = CreateWindowEx(
			0,                               // no extended styles 
			TRACKBAR_CLASS,                  // class name 
			"Trackbar Control",              // title (caption) 
			getStyle(),              // style 
			getXPos(), getYPos(),                          // position 
			getWidth(), getHeight(),                         // size 
			parentHandle,                         // parent window 
			(HMENU)ID,                     // control identifier 
			GetModuleHandle(0),                         // instance 
			NULL                             // no WM_CREATE parameter 
		);
	}
	VOID setMinMaxValue(INT min, INT max) { SendMessage(handle, TBM_SETRANGE, (WPARAM)TRUE, (LPARAM)MAKELONG(min, max)); }
	VOID setAutoTicks() { INT style = getStyle(); style += TBS_AUTOTICKS; setStyle(style); }
	INT getValue() { int pos = SendMessage(handle, TBM_GETPOS, 0, 0); return pos; }
};