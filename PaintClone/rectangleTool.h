#pragma once
#include "tool.h"

class RectangleTool : public Tool
{
public:
	RectangleTool(std::string displayName, std::string descriptionAndTutorial)
	: Tool(displayName, descriptionAndTutorial) { }

	virtual void Update() override;
	virtual void HandleEvent(sf::Event &currentEvent) override { }
	virtual void CleanUp() override { }
	virtual void Draw() override { }

	virtual void Select();
	virtual void Deselect();
	virtual void DrawToCanvas() { }
};

