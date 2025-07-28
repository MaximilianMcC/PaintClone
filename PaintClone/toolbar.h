#pragma once
#include "thing.h"

class Toolbar : public Thing
{
private:
	sf::RectangleShape toolSelector;
	sf::RectangleShape toolSettings;
	// std::vector<Tool> tools;


public:
	Toolbar();
	void Start() override;
	void HandleEvent(sf::Event &event) override;
	// void Update() override;
	void Draw() override;

	void ResizeUi();
};