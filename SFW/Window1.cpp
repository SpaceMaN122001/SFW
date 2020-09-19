#include "Window1.h"

Window1::Window1()
{
	setText("SFW GUI");
	setFixedSize();
	setSize(300, 300);
	Initial((WNDPROC)windowProcedure);
	//ui.setupUi(this);

	slider = new SFSlider(this);
	slider->setPosition(0, 0);
	slider->setSize(200, 70);
	slider->setAutoTicks();
	slider->Show();
	slider->setMinMaxValue(0, 5);

	SFSlider* slider2 = new SFSlider(this);
	slider2->setPosition(0, 80);
	slider2->setSize(200, 70);
	slider2->setAutoTicks();
	slider2->Show();
	slider2->setMinMaxValue(0, 15);
}

Window1::~Window1()
{
}

VOID Window1::test()
{
	SFMessageBox::Show("", "", Warning | OK);
}

long Window1::windowProcedure(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	Window1* wnd = NULL;

	if (Message == Init) {

		wnd = setWindowLong<Window1>(hwnd, lParam);
	}

	wnd = getWindowLong<Window1>(wnd, hwnd);

	if (Message == Close) SFApplication::Quit();

	if(Message == Pressing) wnd->setFocus();

	return defaultMessageHandling;
}