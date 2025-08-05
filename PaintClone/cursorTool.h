#pragma once
#include "tool.h"

class CursorTool : public Tool
{
public:
	CursorTool(std::string displayName, std::string descriptionAndTutorial)
	: Tool(displayName, descriptionAndTutorial) { }
};