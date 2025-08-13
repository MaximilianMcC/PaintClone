/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : imageButton
Description : image button
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "button.h"
#include "assetManager.h"

class ImageButton : public Button
{
private:
	std::optional<sf::Sprite> texture;

public:
	ImageButton(sf::Texture* image, sf::Vector2f size, sf::Vector2f position, sf::Keyboard::Key shortcutKey = sf::Keyboard::Key::Unknown);
	ImageButton(std::string imagePath, sf::Vector2f size, sf::Vector2f position, sf::Keyboard::Key shortcutKey = sf::Keyboard::Key::Unknown);

	void Draw() override;
};