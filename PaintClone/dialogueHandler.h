#pragma once
#include <string>
#include <Windows.h>
#include "program.h"

class DialogueHandler
{
public:

    //? Will return true for save, false for not save
    static bool ConfirmSaveMessageBox();
};