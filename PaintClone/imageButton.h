#pragma once
#include "button.h"
#include "assetManager.h"

class ImageButton : public Button
{
private:
	std::optional<sf::Sprite> texture;

public:
	ImageButton(sf::Texture* image, sf::Vector2f size, sf::Vector2f position);
	ImageButton(std::string imagePath, sf::Vector2f size, sf::Vector2f position);

	void Draw() override;
};