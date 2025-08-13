/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : cursorTool
Description : does legit nothing but photoshop has it so I added it 
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "tool.h"

class CursorTool : public Tool
{
public:
	CursorTool(std::string displayName, std::string descriptionAndTutorial)
	: Tool(displayName, descriptionAndTutorial) { }

	void Select() override;
	void Deselect() override;
};