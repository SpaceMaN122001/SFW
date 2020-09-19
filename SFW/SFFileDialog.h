#pragma once
#include "SFWidget.h"
#include "shlwapi.h"
#include "Shlobj.h"

class SFFileDialog
{
public:
	SFFileDialog();
	~SFFileDialog();
	static std::string getOpenFilePath(const char filter[] = "All\0*.*\0Text\0*.TXT\0", SFWidget* window = NULL);
	static std::string getOpenFileName(const char filter[] = "All\0*.*\0Text\0*.TXT\0", SFWidget* window = NULL);
	static std::string getSelectedDirPath(std::string title = "Select folder", SFWidget* window = NULL);
	static std::string getSelectedDirName(std::string title = "Select folder", SFWidget* window = NULL);
private:
	static std::string getFileName(std::string pathToFile);
};