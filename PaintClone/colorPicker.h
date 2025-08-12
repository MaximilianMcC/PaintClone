#pragma once
#include "thing.h"
#include "dialogueHandler.h"
#include "utils.h"
#include "button.h"
#include "toolbar.h"

class ColorPicker : public Thing
{
private:
	sf::Color fillColor;
	sf::Color outlineColor;

	Button* fillColorButton;
	Button* outlineColorButton;

public:
	void Start() override;
	virtual void HandleEvent(sf::Event &currentEvent) override;
	void Draw() override;

	sf::Color GetFillColor();
	sf::Color GetOutlineColor();

	void SetFillColor();
	void SetOutlineColor();

	std::function<void()> Pick(Button* colorPickerButton, sf::Color* colorToPick);
};

