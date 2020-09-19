#pragma once
#include "SFWidget.h"

enum Icon
{
	Warning = MB_ICONWARNING,
	Error = MB_ICONERROR,
	Information = MB_ICONINFORMATION,
	Stop = MB_ICONSTOP

};

enum Button
{
	CancelTryContinue = MB_CANCELTRYCONTINUE,
	OK = MB_OK,
	OKCancel = MB_OKCANCEL,
	YesNo = MB_YESNO,
	YesNoCancel = MB_YESNOCANCEL,
	RetryCancel = MB_RETRYCANCEL
};

enum MessageBoxEvent
{
	IOK = 1,
	ICancel = 2,
	IBort = 3,
	IRetry = 4,
	IGnore = 5,
	IYes = 6,
	INo = 7,
	IClose = 8,
	IHelp = 9,
	ITryAgain = 10,
	IContinue = 11,
};

class SFMessageBox
{
public:
	SFMessageBox();
	~SFMessageBox();
	static INT Show(std::string text, std::string title, INT attributes = Information | OK, SFWidget* widget = NULL);
};

