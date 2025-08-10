#include "shapeTool.h"

void ShapeTool::Select()
{
	// Switch the mouse cursor to be more representative of the shape
	Utils::SetCursor(sf::Cursor::Type::Cross);
}

void ShapeTool::Deselect()
{
	Utils::ResetCursor();
}

void ShapeTool::Update()
{
	// Check for if we're holding down the mouse
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false)
	{
		// Check for if we were previously making a shape
		if (makingShapeRn)
		{
			// We've finished making the shape.
			// Place it on the canvas
			// TODO: Place it on the canvas
		}

		// Say that we've finished now
		makingShapeRn = false;
		return;
	}
	
	// Check for if we're on the canvas rn
	sf::Vector2f mousePosition;
	if (Utils::GetCanvas()->GetMousePosition(mousePosition) == false) return;

	// Check for if we were previously making a
	// shape or if this is the first time making it
	if (makingShapeRn == false)
	{
		// Say that we're making one now
		makingShapeRn = true;

		// Actually make the shape
		MakeNewShape();
		shape->setPosition(mousePosition);
		shape->setFillColor(sf::Color::Magenta);
		shape->setOutlineColor(sf::Color::Red);
	}

	// Get the new size of the shape from the mouse position
	sf::Vector2f newSize = sf::Vector2f(
		mousePosition.x - shape->getPosition().x,
		mousePosition.y - shape->getPosition().y
	);
	ResizeShape(newSize);
}

void ShapeTool::DrawOnCanvas()
{
	// Draw the shape to the canvas (wow)
	Utils::GetCanvas()->GetRenderTexture()->draw(*shape);
}

void ShapeTool::CleanUp()
{
	delete shape;
	shape = nullptr;
	std::cout << "make sure ts runs" << std::endl;
}