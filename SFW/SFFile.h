#pragma once
#include <Windows.h>
#include <WinBase.h>
#include <string>

enum File
{
	ReadOnly = GENERIC_READ,
	WriteOnly = GENERIC_WRITE,
	ShareWriteOnly = FILE_SHARE_WRITE,
	ShareReadOnly = FILE_SHARE_READ,
	NewFile = CREATE_NEW,
	OverWrite = CREATE_ALWAYS
};

class SFFile
{
public:
	SFFile(std::string fileName = nullptr);
	~SFFile();
	HANDLE getFileHandle();
	VOID setFileName(std::string fileName);
	bool createFile(int access, int generalAcces, int action);
	bool openFile();
	//bool renameFile();
	VOID Write(std::string text);
	VOID Write(const char* text);
	VOID WriteToEnd(std::string text);
	VOID WriteToEnd(const char* text);
	bool isExist();
	static bool isExist(std::string fileName);
private:
	HANDLE _file;
	std::string _fileName;
};

