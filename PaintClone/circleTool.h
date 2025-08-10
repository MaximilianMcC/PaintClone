#pragma once
#include "tool.h"
#include "shapeTool.h"

class CircleTool : public ShapeTool
{	
private:
	void MakeNewShape();
	void ResizeShape(sf::Vector2f newSize);
	
public:
	CircleTool(std::string displayName, std::string descriptionAndTutorial)
	: ShapeTool(displayName, descriptionAndTutorial) { }
};

