#pragma once
#include "SFML/Graphics.hpp"

class Thing
{
public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime, sf::RenderWindow& window) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};