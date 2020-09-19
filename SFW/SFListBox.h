#pragma once
#include "SFWidget.h"
#include <map>

class SFListBox : public SFWidget
{
public:
	SFListBox(SFWidget* widget);
	~SFListBox();
	virtual VOID Show(int value = 1) override;
	VOID addItem(std::string itemText);
	std::string getItemText(UINT index);
private:
	std::map<UINT, std::string> indexes;
};

