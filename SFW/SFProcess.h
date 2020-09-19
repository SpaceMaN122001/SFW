#pragma once
#include "SFWidget.h"
#include <tlhelp32.h>
#include <vector>

class SFProcess
{
public:
	SFProcess(SFWidget* window);
	~SFProcess();
	VOID Start(std::string pathToExe);
	static VOID Start(SFWidget* window, std::string pathToExe);
	static VOID killProcess();
	static bool isProcessRun(std::string processName);
private:
	HWND _parentHwnd;
};