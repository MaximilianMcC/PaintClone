#include "dialogueHandler.h"

bool DialogueHandler::ConfirmSaveMessageBox()
{
	// TODO: Use the SFML window handle
	HWND window = nullptr;

	int result = MessageBox(
		window,
		L"surely you're saving rn",
		L"erhm",
		MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2
	);

	return result == IDYES;
}