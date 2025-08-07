#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

// TODO: Get rid of this class and do it in utils
// TODO: Write this stuff in cpp files. Gotten too large (cursor)
class Utils
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
	static void Init(float* deltaTimePointer, sf::RenderWindow* renderWindowPointer);

	static float GetDeltaTime();
	static sf::RenderWindow* GetWindow();
	static sf::Vector2f GetWindowSize();

	// Get the mouse position relative to the window, and
	// return it as a float rather that int
	static sf::Vector2f GetMousePosition();

	static void SetCursor(sf::Cursor::Type cursorType, bool temporary = false, bool force = true);
	static void SetCursorToPrevious();
	static void ResetCursor();

	static void PrintVector(sf::Vector2f vector);
	static void PrintVector(sf::Vector2u vector);
};