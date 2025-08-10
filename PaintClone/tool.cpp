#include "tool.h"

Tool::Tool(std::string displayName, std::string descriptionAndTutorial)
{
	name = displayName;
	info = descriptionAndTutorial;
}

std::string Tool::GetName()
{
	return name;
}

std::string Tool::GetInfo()
{
	return info;
}

void Tool::SetInfo(std::string newInfo)
{
	info = newInfo;
}