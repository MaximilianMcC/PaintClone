/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : colorPicker
Description : stores colors
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "thing.h"
#include "dialogueHandler.h"
#include "utils.h"
#include "button.h"

class ColorPicker : public UiElement
{
private:
	sf::Color fillColor;
	sf::Color outlineColor;

	Button* fillColorButton;
	Button* outlineColorButton;

public:
	ColorPicker();

	void Start() override;
	void Update() override;
	virtual void HandleEvent(sf::Event &currentEvent) override;
	void Draw() override;
	void CleanUp() override;

	sf::Color GetFillColor();
	sf::Color GetOutlineColor();

	void ResizeUi();

	void SetFillColor();
	void SetOutlineColor();

	std::function<void()> Pick(Button* colorPickerButton, sf::Color* colorToPick);
};

