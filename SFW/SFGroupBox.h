#pragma once
#include "SFWidget.h"

class SFGroupBox : public SFWidget
{
public:
	SFGroupBox(SFWidget* window);
	~SFGroupBox();
	virtual VOID Show(int value = 1) override;
};