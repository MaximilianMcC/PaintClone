#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

// TODO: Get rid of this class and do it in utils
// TODO: Write this stuff in cpp files. Gotten too large (cursor)
class Program
{
private:
	// TODO: Use references for most of these (floats especially)
	static float* deltaTime;
	static sf::RenderWindow* window;

	static sf::Cursor::Type currentCursor;
	static sf::Cursor::Type previousCursor;
	static bool usingTemporaryCursor;
	static sf::Cursor::Type temporaryCursor;

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

	// A temporary cursor will not be added to the previous cursor thing
	static void SetCursor(sf::Cursor::Type cursorType, bool temporary = false, bool force = false)
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

	static void SetCursorToPrevious()
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

	static void ResetCursor()
	{
		SetCursor(sf::Cursor::Type::Arrow);
		usingTemporaryCursor = false;
	}
};