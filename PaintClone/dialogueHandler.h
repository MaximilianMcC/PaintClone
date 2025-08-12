#pragma once
#include <string>
#include <Windows.h>
#include <commdlg.h>
#include "utils.h"

class DialogueHandler
{
public:

	//? Will return true for save, false for not save
	static bool ConfirmSaveMessageBox();
	
	static sf::Color LaunchColorPicker(sf::Color previousColor);
};