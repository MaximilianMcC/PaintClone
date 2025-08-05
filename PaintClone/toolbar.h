#pragma once
#include "thing.h"
#include "tool.h"
#include "button.h"
#include "imageButton.h"

class Toolbar : public Thing
{
private:
	sf::RectangleShape toolSelector;
	sf::RectangleShape toolSettings;
	
	std::vector<UiElement*> uiElements;
	std::vector<Tool*> tools;
	Tool* currentTool;

	void CreateToolsAndButtons(float columnWidth);

public:
	Toolbar();
	void Start() override;
	void HandleEvent(sf::Event &event) override;
	void Update() override;
	void Draw() override;
	void CleanUp() override;

	void ResizeUi();
	std::function<void()> SetTool(Tool* tool);
};