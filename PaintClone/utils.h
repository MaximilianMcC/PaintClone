/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : utils
Description : random utility stuff. mostly used for sharing stuff
Author : Maximilian Oscar Jack McCarthy
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <Windows.h>

// Stop circular dependncy stuff
class Canvas;
class ColorPicker;

// TODO: Get rid of this class and do it in utils
// TODO: Write this stuff in cpp files. Gotten too large (cursor)
class Utils
{
private:
	// TODO: Use references for most of these (floats especially)
	static float* deltaTime;
	static sf::RenderWindow* window;

	static Canvas* mainCanvas;

	static ColorPicker* colorPicker;

	static sf::Cursor::Type currentCursor;
	static sf::Cursor::Type previousCursor;
	static bool usingTemporaryCursor;
	static sf::Cursor::Type temporaryCursor;

public:
	static void Init(float* deltaTimePointer, sf::RenderWindow* renderWindowPointer);

	static Canvas* GetCanvas();
	static void SetCanvas(Canvas* canvas);

	static float GetDeltaTime();
	static sf::RenderWindow* GetWindow();
	static sf::Vector2f GetWindowSize();

	// Get the mouse position relative to the window, and
	// return it as a float rather that int
	static sf::Vector2f GetMousePosition();

	static void SetCursor(sf::Cursor::Type cursorType, bool temporary = false, bool force = true);
	static void SetCursorToPrevious();
	static void ResetCursor();

	static void SetColorPicker(ColorPicker* newColorPicker);
	static ColorPicker* GetColorPicker();

	static void PrintVector(sf::Vector2f vector);
	static void PrintVector(sf::Vector2u vector);
	static void PrintColor(sf::Color color);

	static COLORREF sfmlColorToWin32(sf::Color color);
	static sf::Color Win32ColorToSfml(COLORREF color);
};