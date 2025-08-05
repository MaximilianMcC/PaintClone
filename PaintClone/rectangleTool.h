#pragma once
#include "tool.h"

class RectangleTool : public Tool
{
public:
	RectangleTool(std::string displayName, std::string descriptionAndTutorial)
	: Tool(displayName, descriptionAndTutorial) { }
};

