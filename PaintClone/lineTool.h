#pragma once
#include "tool.h"
#include "shapeTool.h"

class LineTool : public ShapeTool
{
private:
	float thickness = 10.0f;

	void MakeNewShape();
	void ResizeShape(sf::Vector2f newSize);

public:
	LineTool(std::string displayName, std::string descriptionAndTutorial)
	: ShapeTool(displayName, descriptionAndTutorial) { }
};