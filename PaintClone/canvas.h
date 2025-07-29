#pragma once
#include <SFML/Graphics.hpp>
#include "thing.h"

class Canvas : public Thing
{
private:
	std::optional<sf::Sprite> outputSprite;
	sf::RenderTexture renderTexture;
	sf::Vector2f size;
	sf::Vector2f renderPosition;

	//? Is made to be the same size as the canvas is
	sf::RenderTexture transparentRenderTexture;
	std::optional<sf::Sprite> transparentSprite;
	void RegenerateAndUpdateDynamicCanvasTransparentBackgroundSpriteGridPattern();

	void Zoom(float delta = 0);

public:
	Canvas();
	void Start() override;
	void HandleEvent(sf::Event &event);
	// void Update() override;
	void Draw() override;

	// Get the mouse position relative to the canvas
	//? Returns false if the mouse is not on the canvas
	bool GetMousePosition(sf::Vector2f& position);
};