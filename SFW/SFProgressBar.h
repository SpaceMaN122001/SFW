#pragma once
#include "SFWidget.h"

enum ProgressBarStyle
{
	SmoothLineStyle = 0x01
};

class SFProgressBar : public SFWidget
{
public:
	SFProgressBar(SFWidget* window);
	~SFProgressBar();
	virtual VOID Show(int value = 1) override;
	VOID setValue(int value);
	VOID setMaxValue(int value);
	VOID setMinValue(int value);
	VOID setStyle(int value);
	VOID setLineColor(int r, int g, int b);
	VOID setLineColor(LPARAM color);
private:
	INT _minValue = 0;
	INT _maxValue = 100;
	INT _style;
	LPARAM _lineColor = (LPARAM)RGB(0, 170, 0);
};