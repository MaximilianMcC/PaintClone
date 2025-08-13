/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : rectangleTool
Description : rectangle tool
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "tool.h"
#include "shapeTool.h"

class RectangleTool : public ShapeTool
{	
private:
	void MakeNewShape();
	void ResizeShape(sf::Vector2f newSize);
	
public:
	RectangleTool(std::string displayName, std::string descriptionAndTutorial)
	: ShapeTool(displayName, descriptionAndTutorial) { }
};

