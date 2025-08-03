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