#pragma once
#include "SFWidget.h"

class SFRadioButton : public SFWidget
{
public:
	SFRadioButton(SFWidget* window);
	~SFRadioButton();
	virtual VOID Show(int value = 1) override;
};

