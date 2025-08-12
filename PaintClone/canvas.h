#pragma once
#include <SFML/Graphics.hpp>
#include "thing.h"

class Canvas : public Thing
{
private:
	sf::View camera;
	sf::Vector2f canvasSize;

	std::optional<sf::Sprite> displaySprite;
	sf::RenderTexture displayRenderTexture;
	std::optional<sf::Sprite> workingSprite;
	sf::RenderTexture workingRenderTexture;

	void Zoom(float delta);
	void Pan(float xDelta, float yDelta);

	// TODO: Don't store this here (toolbar or something maybe)
	sf::Color selectedColor;

public:
	Canvas();
	void Start() override;
	void HandleEvent(sf::Event &event);
	void Draw() override;

	// Get the mouse position relative to the canvas
	//? Returns false if the mouse is not on the canvas
	bool GetMousePosition(sf::Vector2f& position);

	sf::RenderTexture* GetDisplayCanvas();
	sf::RenderTexture* GetWorkingCanvas();

	sf::Color GetSelectedColor();
	void SetSelectedColor(sf::Color newColor);
};