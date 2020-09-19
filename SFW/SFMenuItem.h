#pragma once
#include "SFWidget.h"
#include <map>

class SFMenuItem : public SFWidget
{
public:
	SFMenuItem();
	~SFMenuItem();
	HMENU getPopMenu() const { return _popMenu; }
	VOID addMenuItem(std::string menuItemName);
	const std::map<std::string, UINT>& getIDList() const { return _id; }
private:
	HMENU _popMenu;
	std::map<std::string, UINT> _id;
};
