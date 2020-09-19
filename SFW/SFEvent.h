#pragma once
#include <Windows.h>
#include "SFWidget.h"
#include "SFMenuItem.h"
#include <map>

enum Event
{
	Close = WM_DESTROY,
	Create = WM_CREATE,
	KeyPress = WM_KEYDOWN,
	Resize = WM_SIZE,
	MouseLeftPress = WM_LBUTTONDOWN,
	MouseRigthPress = WM_RBUTTONDOWN,
	Quit = WM_QUIT,
	Pressing = WM_COMMAND,
	Init = WM_NCCREATE,
	DoubleClicked = LBN_DBLCLK,
	HorizontalSliderMove = WM_HSCROLL
};

enum Buttons
{
	MouseRigthButton = MK_RBUTTON,
	MouseLeftButton = MK_LBUTTON
};

class SFEvent
{
public:
	SFEvent();
	~SFEvent();
	static bool Pressing(WPARAM wparam, SFWidget* widget);
	static bool Pressing(UINT message, WPARAM wparam, SFWidget* widget);
	static bool DoubleClicked(WPARAM wparam, SFWidget* widget);
	static bool Pressing(WPARAM wparam, UINT id);
	static bool MenuItemPressing(WPARAM wparam, SFMenuItem* item, std::string itemText);
};