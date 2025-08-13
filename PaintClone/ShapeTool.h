/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : shapeTool
Description : parent of all shape tools
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "canvas.h"
#include "ShapeTool.h"
#include "tool.h"
#include "colorPicker.h"

class ShapeTool : public Tool
{
	
protected:
	std::unique_ptr<sf::Shape> shape;
	bool makingShapeRn;

	virtual void MakeNewShape() = 0;
	virtual void ResizeShape(sf::Vector2f newSize) = 0;

public:
	ShapeTool(std::string displayName, std::string descriptionAndTutorial)
	: Tool(displayName, descriptionAndTutorial) { }

	virtual void Update();
	virtual void HandleEvent(sf::Event &currentEvent) override { }
	virtual void CleanUp() { }
	virtual void Draw() override { }
	
	virtual void Select();
	virtual void Deselect();
	virtual void DrawOnCanvas();
};

