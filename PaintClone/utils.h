#pragma once

#include "SFML/Graphics.hpp"

class Utils
{
public:
};

//? This is needed for render textures because a sprite like references an existing texture if that makes sense. Can't exist on its own
struct SpriteWithTexture {
	sf::Texture texture;
	std::optional<sf::Sprite> sprite;
};