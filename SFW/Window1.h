#pragma once
#include "Window1Form.h"
#include <memory>
#include <fstream>

class Window1 : public SFWindow
{
public:
	Window1();
	~Window1();
private:
	static long windowProcedure(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	VOID test();
	SFPushButton* selectFile;
	SFPushButton* createUi;
	SFPushButton* quit;
	SFTextBlock* path;
	Window1Form ui;
	SFMenuItem* item;
	SFSlider* slider;
};