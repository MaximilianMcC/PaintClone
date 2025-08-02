#pragma once
#include "thing.h"
#include "button.h"
#include "imageButton.h"

class Toolbar : public Thing
{
private:
	sf::RectangleShape toolSelector;
	sf::RectangleShape toolSettings;
	
	// std::vector<Tool> tools;

	std::vector<UiElement*> uiElements;
	Button* button;

public:
	Toolbar();
	void Start() override;
	void HandleEvent(sf::Event &event) override;
	void Update() override;
	void Draw() override;
	void CleanUp() override;

	void ResizeUi();
};