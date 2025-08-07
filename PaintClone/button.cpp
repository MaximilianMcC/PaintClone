#include "button.h"

// TODO: Maybe use references or something for these
Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color backgroundColor, sf::Keyboard::Key shortcutKey)
{
	// Make the actual button rectangle
	shape = sf::RectangleShape(size);
	shape.setPosition(position);
	shape.setFillColor(backgroundColor);

	// Set the shortcut key
	shortcut = shortcutKey;

	Start();
}

void Button::Update()
{
	// Check for if we've been clicked
	CheckForClicking();

	// If we have a callback and were clicked then run the callback
	if (IsClicked() && callbackFunction != nullptr) callbackFunction();
}

void Button::CheckForClicking()
{
	// TODO: Don't do this every frame
	previouslyClicked = clicked;
	previouslyHovered = hovered;

	// Check for if we did the shortcut
	if (sf::Keyboard::isKeyPressed(shortcut))
	{
		clicked = true;
		return;
	}

	// Get the mouse position
	sf::Vector2f mousePosition = Utils::GetMousePosition();

	// Check for if we're being hovered
	//? not using guard here because its a little clearer
	if (shape.getGlobalBounds().contains(mousePosition) == false)
	{
		// We aren't hovering
		hovered = false;

		// If we were just hovering then
		// return to the previous cursor
		if (previouslyHovered) Utils::SetCursorToPrevious();
	}
	else
	{
		// We are now hovering
		hovered = true;
		if (previouslyHovered == false)
		{
			// Set the cursor to be the clicky one
			Utils::SetCursor(sf::Cursor::Type::Hand, true);
		}

		// Check for if we clicked on the button
		clicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	}
}

bool Button::IsClicked() { return clicked && previouslyClicked == false; }
bool Button::IsHeld() { return clicked; }
bool Button::IsHovered() { return hovered; }

void Button::Draw()
{
	Utils::GetWindow()->draw(shape);
}

void Button::SetCallback(std::function<void()> methodToCall)
{
	callbackFunction = methodToCall;
}