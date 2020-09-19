#include "SFMessageBox.h"

SFMessageBox::SFMessageBox()
{
}

SFMessageBox::~SFMessageBox()
{
}

INT SFMessageBox::Show(std::string text, std::string title, INT attributes, SFWidget* widget)
{
    HWND hwnd = NULL;

    if(widget == NULL) hwnd = NULL;
    if(widget != NULL) hwnd = widget->getWidgetHandle();

    INT msg = MessageBox(
        hwnd,
        text.c_str(),
        title.c_str(),
        attributes
    );

    return msg;
}