#pragma once
#include "SFWidget.h"

class SFFileInfo
{
public:
	SFFileInfo();
	~SFFileInfo();
	static std::string getFileName(std::string pathToFile);
	static std::string getFileExpansion(std::string fileName);
private:
};