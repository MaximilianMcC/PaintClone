#include "button.h"

// TODO: Maybe use references or something for these
Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color backgroundColor)
{
	// Make the actual button rectangle
	shape = sf::RectangleShape(size);
	shape.setPosition(position);
	shape.setFillColor(backgroundColor);

	Start();
}

void Button::Update()
{
	// Reset variables
	// TODO: Don't do this every frame
	previouslyClicked = clicked;
	hovered = false;
	clicked = false;

	// Get the mouse position
	sf::Vector2f mousePosition = Program::GetMousePosition();

	// Check for if we're being hovered
	// TODO: Make the background color a bit darker if hovering
	if (shape.getGlobalBounds().contains(mousePosition) == false) return;
	hovered = true;

	// Check for if we clicked on the button
	clicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

bool Button::IsClicked() { return clicked && previouslyClicked == false; }
bool Button::IsHeld() { return clicked; }
bool Button::IsHovered() { return hovered; }

void Button::Draw()
{
	Program::GetWindow()->draw(shape);
}