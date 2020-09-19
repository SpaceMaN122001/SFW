#include "SFProcess.h"

SFProcess::SFProcess(SFWidget* window)
{
	_parentHwnd = window->getWidgetHandle();
}

SFProcess::~SFProcess()
{
}

VOID SFProcess::Start(std::string pathToExe)
{
	ShellExecute(_parentHwnd, NULL, pathToExe.c_str(), NULL, NULL, SW_SHOW);
}

VOID SFProcess::Start(SFWidget* window, std::string pathToExe)
{
	ShellExecute(window->getWidgetHandle(), NULL, pathToExe.c_str(), NULL, NULL, SW_SHOW);
}

VOID SFProcess::killProcess()
{
	system("taskkill /IM csgo.exe");
}

bool SFProcess::isProcessRun(std::string processName)
{
	std::vector<std::string> processes;

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;

	pe32.dwSize = sizeof(PROCESSENTRY32);

	while (Process32Next(hProcessSnap, &pe32)) {

		std::string runningProcessName(pe32.szExeFile);
		processes.push_back(runningProcessName);
	}

	for (int i = 0; i < processes.size(); i++) {

		if (processes[i] == processName) return true;
	}

	return false;
}