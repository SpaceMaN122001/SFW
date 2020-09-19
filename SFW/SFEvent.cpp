#pragma once
#include "SFEvent.h"

SFEvent::SFEvent()
{
}

SFEvent::~SFEvent()
{
}

bool SFEvent::Pressing(WPARAM wparam, SFWidget* widget)
{
	try
	{
		if (widget == NULL) return false;

		if (wparam == widget->getWidgetID()) return true;

		return false;
	}
	catch (SFWidget w)
	{
		return false;
	}
}

bool SFEvent::Pressing(WPARAM wparam, UINT id)
{
	if (wparam == id) return true;

	return false;
}

bool SFEvent::MenuItemPressing(WPARAM wparam, SFMenuItem* item, std::string itemText)
{
	std::map<std::string, UINT> id = item->getIDList();

	if (id[itemText] == wparam) return true;

	return false;
}

bool SFEvent::DoubleClicked(WPARAM wparam, SFWidget* widget)
{
	if (LOWORD(wparam) == widget->getWidgetID() && HIWORD(wparam) == LBN_DBLCLK) return true;

	return false;
}

bool SFEvent::Pressing(UINT message, WPARAM wparam, SFWidget* widget)
{
	if (message == WM_COMMAND && wparam == widget->getWidgetID()) return true;

	return false;
}