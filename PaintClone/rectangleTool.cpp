#include "rectangleTool.h"

void RectangleTool::MakeNewShape()
{
	shape = std::make_unique<sf::RectangleShape>();
}

void RectangleTool::ResizeShape(sf::Vector2f newSize)
{
	// Cast the normal shape to a rectnagle, then set its size
	static_cast<sf::RectangleShape*>(shape.get())->setSize(newSize);
}