#include "SFFileInfo.h"

SFFileInfo::SFFileInfo()
{
}

SFFileInfo::~SFFileInfo()
{
}

std::string SFFileInfo::getFileName(std::string pathToFile)
{
	std::string fileName = "";

	int i = 0;
	int j = 0;
	int k = 0;

	for (char s : pathToFile) {

		i++;

		if (s == '\\') j = i;
	}

	for (char s : pathToFile) {

		k++;
		if (k - 1 >= j)
			fileName += s;
	}

	return fileName;
}

std::string SFFileInfo::getFileExpansion(std::string fileName)
{
	std::string s1 = "";
	int i = 0;
	int j = 0;

	for (char s : fileName) {

		i++;

		if (s == '.') break;
	}

	for (char s : fileName) {

		j++;

		if (j >= i) s1 += s;

	}

	return s1;
}