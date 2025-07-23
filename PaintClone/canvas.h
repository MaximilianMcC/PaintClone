#pragma once
#include <SFML/Graphics.hpp>
#include "thing.h"

class Canvas : public Thing
{
private:
	std::optional<sf::Sprite> outputSprite;
	sf::RenderTexture renderTexture;
	sf::RectangleShape canvas;

public:
	Canvas();
	void Start() override;
	void Update() override;
	void Draw() override;

	// Returns false if the mouse is not on the canvas
	bool GetMousePosition(sf::Vector2f& position);
};