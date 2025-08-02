#pragma once
#include "button.h"
#include "assetManager.h"

class ImageButton : public Button
{
private:
	std::optional<sf::Sprite> image;

public:
	ImageButton(std::string imageKey, sf::Vector2f size, sf::Vector2f position);

	void Draw() override;
};