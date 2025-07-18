#include "SFML/Graphics.hpp";

#pragma once
class Thing
{
public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};

