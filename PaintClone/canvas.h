#pragma once
#include <SFML/Graphics.hpp>
#include "thing.h"

class Canvas : public Thing
{
private:
	float zoom;
	sf::RenderTexture renderTexture;
	sf::RectangleShape canvas;

public:
	Canvas();
	void Start() override;
	void Update() override;
	void Draw() override;

	// Returns false if the mouse is not on the canvas
	bool GetMousePosition(sf::Vector2f& position);

	// Zoom getters and setters
	// TODO: Don't wite in H
	float GetZoom()
	{
		return zoom;
	}
	void SetZoom(float newZoom)
	{
		zoom = newZoom;
	}
};