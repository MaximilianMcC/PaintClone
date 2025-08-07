#pragma once
#include <SFML/Graphics.hpp>
#include "thing.h"

class Canvas : public Thing
{
private:
	sf::View camera;

	sf::RenderTexture renderTexture;
	std::optional<sf::Sprite> sprite;
	sf::Vector2f canvasSize;

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