#include "CircleTool.h"

void CircleTool::MakeNewShape()
{
	shape = new sf::CircleShape();
}

void CircleTool::ResizeShape(sf::Vector2f newSize)
{
	// Calculate the radius from the new size
	float newRadius = std::max(newSize.x, newSize.y) / 2.0f;

	// Cast the normal shape to a circle, then set its radius
	static_cast<sf::CircleShape*>(shape)->setRadius(newRadius);
}