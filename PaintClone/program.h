#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class Program
{
private:
	// TODO: Use references for most of these (floats especially)
	static float* deltaTime;
	static sf::RenderWindow* window;

	static sf::Cursor::Type currentCursor;
	static sf::Cursor::Type previousCursor;

public:
	// TODO: Don't write in H
	// TODO: Make a singleton or something idk
	static void Init(float* deltaTimePointer, sf::RenderWindow* renderWindowPointer)
	{
		// Assign the pointers so every 'thing' doesn't have have
		// them all manually passed (annoying (waste of time))
		deltaTime = deltaTimePointer;
		window = renderWindowPointer;
	}

	static float GetDeltaTime()
	{
		return *deltaTime;
	}

	static sf::RenderWindow* GetWindow()
	{
		return window;
	}

	// Get the mouse position relative to the window, and
	// return it as a float rather that int
	static sf::Vector2f GetMousePosition()
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*GetWindow());
		return static_cast<sf::Vector2f>(mousePosition);
	}

	static void SetCursor(sf::Cursor::Type cursorType)
	{
		// Check for if there is actually a change to do
		if (currentCursor == cursorType) return;

		// Store the current and previous cursor
		previousCursor = currentCursor;
		currentCursor = cursorType;

		window->setMouseCursor(sf::Cursor(currentCursor));
	}

	static void SetCursorToPrevious()
	{
		SetCursor(previousCursor);
	}

	static void ResetCursor()
	{
		SetCursor(sf::Cursor::Type::Arrow);
	}
};