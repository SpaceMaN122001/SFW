#include "SFTextBlock.h"
#include "SFMessageBox.h"

SFTextBlock::SFTextBlock(SFWidget* window)
{
	parentHandle = window->getWidgetHandle();
}

SFTextBlock::~SFTextBlock()
{
}

VOID SFTextBlock::Show(int value)
{
	handle = CreateWindow(
		"STATIC",
		getText().c_str(),
		WS_CHILD | WS_VISIBLE | SS_LEFT,
		getXPos(),
		getYPos(),
		getWidth(),
		getHeight(),
		parentHandle,
		NULL,
		NULL,
		NULL
	);
}