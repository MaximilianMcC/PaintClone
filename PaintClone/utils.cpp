#pragma once

#include "utils.h"
#include "colors.h"

float* Utils::deltaTime = nullptr;
sf::RenderWindow* Utils::window = nullptr;

sf::Cursor::Type Utils::currentCursor = sf::Cursor::Type::Arrow;
sf::Cursor::Type Utils::previousCursor = sf::Cursor::Type::Arrow;
bool Utils::usingTemporaryCursor = false;
sf::Cursor::Type Utils::temporaryCursor;

ColorTheme Colors::Theme = Colors::Light;


void Utils::Init(float* deltaTimePointer, sf::RenderWindow* renderWindowPointer)
{
	// Assign the pointers so every 'thing' doesn't have have
	// them all manually passed (annoying (waste of time))
	deltaTime = deltaTimePointer;
	window = renderWindowPointer;
}

float Utils::GetDeltaTime()
{
	return *deltaTime;
}

sf::RenderWindow* Utils::GetWindow()
{
	return window;
}

// Get the mouse position relative to the window, and
// return it as a float rather that int
sf::Vector2f Utils::GetMousePosition()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*GetWindow());
	return static_cast<sf::Vector2f>(mousePosition);
}

// A temporary cursor will not be added to the previous cursor thing
void Utils::SetCursor(sf::Cursor::Type cursorType, bool temporary = false, bool force = false)
{
	// Check for if there is actually a change to do
	if (!force && currentCursor == cursorType) return;

	// If its a temporary cursor then don't
	// count this as an actual change
	// TODO: Make new cursor a pointer idk (is just an int though (waste))
	sf::Cursor::Type newCursor;
	if (temporary == true)
	{
		// Set it to the requested cursor without
		// noting down what we've set it to
		usingTemporaryCursor = true;
		temporaryCursor = cursorType;

		newCursor = temporaryCursor;
	}
	else
	{
		// Store the current and previous cursor
		previousCursor = currentCursor;
		currentCursor = cursorType;

		newCursor = currentCursor;
	}

	// Actually set the cursor
	window->setMouseCursor(sf::Cursor(newCursor));

	// Debug
	std::cout << "cursor is now:\t\t" << (int)currentCursor << std::endl;
	std::cout << "previous cursor is now:\t" << (int)previousCursor << std::endl;
}

void Utils::SetCursorToPrevious()
{
	// If we were using a temp cursor then don't
	// revert to the previous, instead revert
	// to the current if that makes any sense
	if (usingTemporaryCursor)
	{
		SetCursor(currentCursor, false, true);
		usingTemporaryCursor = false;
		return;
	}

	// Revert back to the previous
	SetCursor(previousCursor);
}

// Make the cursor an arrow
void Utils::ResetCursor()
{
	SetCursor(sf::Cursor::Type::Arrow);
	usingTemporaryCursor = false;
}