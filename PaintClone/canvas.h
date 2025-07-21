#pragma once
#include <SFML/Graphics.hpp>
#include "thing.h"

class Canvas
{
private:
	static sf::Vector2u size;
	static sf::RenderTexture renderTexture;
	static float zoom;

public:
	static void Start();
	static void Update(float deltaTime, sf::RenderWindow& window);
	static void Draw(sf::RenderWindow& window);

	// Size getters and setters
	// TODO: Don't write in H (switch to hpp or cpp idk)
	static sf::Vector2u GetSize()
	{
		return size;
	}
	static void SetSize(int newWidth, int newHeight)
	{
		// TODO: Use ctor
		size = sf::Vector2u(newWidth, newHeight);
	}
	static void SetSize(sf::Vector2u newSize)
	{
		size = newSize;
	}

	// Zoom getters and setters
	// TODO: Don't wite in H
	static float GetZoom()
	{
		return zoom;
	}
	static void SetZoom(float newZoom)
	{
		zoom = newZoom;
	}
};