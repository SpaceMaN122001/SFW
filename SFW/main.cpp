#include <iostream>
#include "Window1.h"
// left ������ bottom ������
//(this->*func)();

int main()
{
	Window1* w = new Window1;
	w->Show();

	SFApplication app;
	app.Exec();

	return 0;
}