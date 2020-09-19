#pragma once
#include "SFWindow.h"

class SFPushButton : public SFWidget
{
public:
	SFPushButton(SFWidget* window, std::string text = "SFButton", INT x = 0, INT y = 0, UINT width = 100, UINT heigth = 50);
	~SFPushButton();
	virtual VOID Show(int value = 1) override;
};