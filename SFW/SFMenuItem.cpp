#include "SFMenuItem.h"

SFMenuItem::SFMenuItem()
{
	_popMenu = CreatePopupMenu();
}

SFMenuItem::~SFMenuItem()
{
}

VOID SFMenuItem::addMenuItem(std::string menuItemName)
{
	UINT id = getUniqueID();
	AppendMenu(_popMenu, MF_STRING, id, menuItemName.c_str());

	_id[menuItemName] = id;
}