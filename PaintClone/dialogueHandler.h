#pragma once
#include <string>
#include <Windows.h>
#include <commdlg.h>
#include <shlobj.h>
#include "utils.h"

class DialogueHandler
{
private:
    static OPENFILENAMEA MakeFileDialogue(const char* title);

public:

	//? Will return true for save, false for not save
	static bool ConfirmSaveMessageBox();
	
	static sf::Color LaunchColorPicker(sf::Color previousColor);

	static std::string LaunchOpenFileDialogue();
	static std::string LaunchSaveFileDialogue();
};