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

