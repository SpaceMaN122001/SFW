#include "SFMenu.h"

SFMenu::SFMenu(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();

	_menu = CreateMenu();
}

SFMenu::~SFMenu()
{
}

VOID SFMenu::addMenu(SFMenuItem* item, std::string menuName)
{
	AppendMenu(_menu, MF_STRING | MF_POPUP, (UINT)item->getPopMenu(), menuName.c_str());

	_pops.push_back(item->getPopMenu());
}

VOID SFMenu::Show(int value)
{
	SetMenu(parentHandle, _menu);
	
	for (int i = 0; i < _pops.size(); i++) {

		SetMenu(parentHandle, _pops[i]);
	}
}