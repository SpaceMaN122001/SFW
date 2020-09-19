#pragma once
#include "SFWidget.h"

class SFTextEdit : public SFWidget
{
public:
	SFTextEdit(SFWidget* window);
	~SFTextEdit();
	virtual VOID Show(int value = 1) override;
	std::string getText();
	VOID setText(std::string text);
};