#pragma once
#include "SFML/Graphics.hpp"
#include "program.h"


class Camera
{
private:
	sf::Vector2f zoom = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f target = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f targetRenderOffset = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f size = sf::Vector2f(0.0f, 0.0f);

	//! sprite might need to be std::optional
	sf::RenderTexture camera;
	sf::Sprite outputSprite;

public:
	Camera(sf::Vector2f size);


	// Actually draw to the camera
	void DrawToCamera(sf::Drawable* thingToDraw);

	// Draw the output of the camera to the window
	void DrawOutput();



	// Zooming
	void SetZoom(float newZoom);
	void AddZoom(float zoomToAdd);

	// Position stuff
	void SetPosition(sf::Vector2f position);

	// Set the target coordinates (cameras position in world)
	void SetTarget(sf::Vector2f position);

	// Set the render offset (Where camera starts drawing from)
	//? using the 0.x stuff, not actual coordinates
	void SetTargetRenderOffset(sf::Vector2f offset);

	// The actual dimensions of the render texture
	void SetSizeAndMakeView(sf::Vector2f newSize);
};