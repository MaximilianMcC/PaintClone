#include <SFML/Graphics.hpp>
#include "thing.h"

#pragma once
class Canvas
{
public:
	Canvas();
	void TempUpdate(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
private:
	sf::RenderTexture renderTexture;
};