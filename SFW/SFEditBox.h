#pragma once
#include "SFWidget.h"
class SFEditBox : public SFWidget
{
public:
	SFEditBox(SFWidget* window);
	~SFEditBox();
	virtual VOID Show(int value = 1) override;
};

