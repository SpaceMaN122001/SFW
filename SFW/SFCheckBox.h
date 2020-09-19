#pragma once
#include "SFWidget.h"

//enum State
//{
//	Checked = 0x0001,
//	UnChecked = 0x0000
//};

class SFCheckBox : public SFWidget
{
public:
	SFCheckBox(SFWidget* window);
	~SFCheckBox();
	virtual VOID Show(int value = 1) override;
	/*VOID setState(INT state) { SendMessage(handle, BM_SETCHECK, state, 0); _state = state; }
	INT getState() const { return _state; }*/
private:
	/*INT _state;*/
};

