/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : slider
Description : slider ui element
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "thing.h"

class Slider : UiElement
{
private:
	float* percentage;

	// TODO: don't let label get away with being special
	sf::RectangleShape line;
	sf::RectangleShape hitbox;
	sf::CircleShape handle;
	std::optional<sf::Text> label;

public:
	Slider();
	Slider(float* percentage, sf::Vector2f position, float lineLength, std::string labelText);

	void Update() override;
	void Draw() override;

	float GetPercentage();
	void SetPercentage(float percentage);
};