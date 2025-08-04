#include "tool.h"

Tool::Tool(std::string displayName, std::string descriptionAndTutorial)
{
	name = displayName;
	info = descriptionAndTutorial;
}

void Tool::Select()
{
	std::cout << "Selected the " << name << " tool" << std::endl;
}