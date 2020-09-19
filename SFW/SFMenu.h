#pragma once
#include "SFWidget.h"
#include "SFMenuItem.h"
#include <vector>

class SFMenu : public SFWidget
{
public:
	SFMenu(SFWidget* window);
	~SFMenu();
	VOID addMenu(SFMenuItem* item, std::string menuName);
	virtual VOID Show(int value = 1) override;
private:
	HMENU _menu;
	HMENU _popMenu;
	std::vector<HMENU> _pops;
};