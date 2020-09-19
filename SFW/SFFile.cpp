#include "SFFile.h"

SFFile::SFFile(std::string fileName)
{
	_fileName = fileName;
}

SFFile::~SFFile()
{
	CloseHandle(_file);
}

HANDLE SFFile::getFileHandle()
{
	return _file;
}

VOID SFFile::setFileName(std::string fileName)
{
	_fileName = fileName;
}

bool SFFile::createFile(int access, int generalAcces, int action)
{
	const char* pathToFile = _fileName.c_str();
	
	_file = CreateFile(pathToFile, access, generalAcces, NULL, action, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

	return true;
}

bool SFFile::openFile()
{
	const char* pathToFile = _fileName.c_str();

	_file  = CreateFile(
		pathToFile,     // Filename
		GENERIC_READ | GENERIC_WRITE,          // Desired access
		FILE_SHARE_READ,        // Share mode
		NULL,                   // Security attributes
		OPEN_EXISTING,             // Creates a new file, only if it doesn't already exist
		FILE_ATTRIBUTE_NORMAL,  // Flags and attributes
		NULL);

	if (_file != INVALID_HANDLE_VALUE) return true;
	else return false;
}

bool SFFile::isExist()
{
	const char* pathToFile = _fileName.c_str();

	HANDLE file = CreateFile(pathToFile,               // file to open
		GENERIC_READ,          // open for reading
		FILE_SHARE_READ,       // share for reading
		NULL,                  // default security
		OPEN_EXISTING,         // existing file only
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
		NULL);

	if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return true;}
	else { CloseHandle(file); return false; }
}

bool SFFile::isExist(std::string fileName)
{
	const char* pathToFile = fileName.c_str();

	HANDLE file = CreateFile(pathToFile,               // file to open
		GENERIC_READ,          // open for reading
		FILE_SHARE_READ,       // share for reading
		NULL,                  // default security
		OPEN_EXISTING,         // existing file only
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
		NULL);

	if (file != INVALID_HANDLE_VALUE) { CloseHandle(file); return true; }
	else { CloseHandle(file); return false; }
}

VOID SFFile::Write(std::string text)
{
	DWORD bytes;
	WriteFile(_file, text.c_str(), text.size(), &bytes, nullptr);
}

VOID SFFile::WriteToEnd(std::string text)
{
	DWORD bytes;
	SetFilePointer(_file, 0, NULL, FILE_END);
	WriteFile(_file, text.c_str(), text.size(), &bytes, nullptr);
}

VOID SFFile::Write(const char* text)
{
	DWORD bytes;
	WriteFile(_file, text, sizeof(text), &bytes, nullptr);
}

VOID SFFile::WriteToEnd(const char* text)
{
	DWORD bytes;
	SetFilePointer(_file, 0, NULL, FILE_END);
	WriteFile(_file, text, sizeof(text), &bytes, nullptr);
}