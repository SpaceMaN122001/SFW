#pragma once
#include "SFWidget.h"

class SFTextBlock : public SFWidget
{
public:
	SFTextBlock(SFWidget* window);
	~SFTextBlock();
	virtual VOID Show(int value = 1) override;
};