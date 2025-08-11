#include "CircleTool.h"

void CircleTool::MakeNewShape()
{
	shape = std::make_unique<sf::CircleShape>(1, 64u);
}

void CircleTool::ResizeShape(sf::Vector2f newSize)
{
	// Cast the normal shape to a circle then change its scale
	//? Must use scale because a sfml circle only had a radius
	static_cast<sf::CircleShape*>(shape.get())->setScale(sf::Vector2f(
		newSize.x / 2.0f,
		newSize.y / 2.0f
	));
}