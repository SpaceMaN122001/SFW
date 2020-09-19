#include "SFFileDialog.h"

SFFileDialog::SFFileDialog()
{
}

SFFileDialog::~SFFileDialog()
{
}

std::string SFFileDialog::getOpenFilePath(const char filter[], SFWidget* window)
{
	char szFile[100];
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = window->getWidgetHandle();
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.lpstrFileTitle = szFile;
	ofn.nMaxFile = sizeof(szFile);
	//ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.lpstrFilter = filter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	GetOpenFileName(&ofn);

	char* a = ofn.lpstrFile;

	std::string s1(a);

	return s1;
}
std::string SFFileDialog::getOpenFileName(const char filter[], SFWidget* window)
{
	char szFile[100];
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = window->getWidgetHandle();
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.lpstrFileTitle = szFile;
	ofn.nMaxFile = sizeof(szFile);
	//ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.lpstrFilter = filter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	GetOpenFileName(&ofn);

	char* a = ofn.lpstrFile;

	std::string s1(a);

	return SFFileDialog::getFileName(s1);
}

std::string SFFileDialog::getSelectedDirPath(std::string title, SFWidget* window)
{
	std::string folderpath = "";

	BROWSEINFO bi;
	memset(&bi, 0, sizeof(bi));

	bi.ulFlags = BIF_USENEWUI;
	bi.hwndOwner = window->getWidgetHandle();
	bi.lpszTitle = title.c_str();

	::OleInitialize(NULL);


	LPITEMIDLIST pIDL = ::SHBrowseForFolder(&bi);

	if (pIDL != NULL) {

		char buffer[_MAX_PATH] = { '\0' };

		if (::SHGetPathFromIDList(pIDL, buffer) != 0) {

			folderpath = buffer;
		}

		CoTaskMemFree(pIDL);
	}

	::OleUninitialize();

	return folderpath;
}

std::string SFFileDialog::getSelectedDirName(std::string title, SFWidget* window)
{
	std::string folderpath = "";

	BROWSEINFO bi;
	memset(&bi, 0, sizeof(bi));

	bi.ulFlags = BIF_USENEWUI;
	bi.hwndOwner = window->getWidgetHandle();
	bi.lpszTitle = title.c_str();

	::OleInitialize(NULL);


	LPITEMIDLIST pIDL = ::SHBrowseForFolder(&bi);

	if (pIDL != NULL) {

		char buffer[_MAX_PATH] = { '\0' };

		if (::SHGetPathFromIDList(pIDL, buffer) != 0) {

			folderpath = buffer;
		}

		CoTaskMemFree(pIDL);
	}

	::OleUninitialize();

	return SFFileDialog::getFileName(folderpath);
}


std::string SFFileDialog::getFileName(std::string pathToFile)
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