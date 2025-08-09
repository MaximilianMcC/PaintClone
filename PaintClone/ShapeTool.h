#pragma once
#include "ShapeTool.h"
#include "tool.h"

class ShapeTool : public Tool
{
	
protected:
	sf::Shape* shape;
	bool makingShapeRn;

	virtual void MakeNewShape() = 0;
	virtual void ResizeShape(sf::Vector2f newSize) = 0;

public:
	ShapeTool(std::string displayName, std::string descriptionAndTutorial)
	: Tool(displayName, descriptionAndTutorial) { }

	virtual void Update();
	virtual void HandleEvent(sf::Event &currentEvent) override { }
	virtual void CleanUp();
	virtual void Draw() override { }
	
	virtual void Select();
	virtual void Deselect();
	virtual void DrawToCanvas() { }
};

