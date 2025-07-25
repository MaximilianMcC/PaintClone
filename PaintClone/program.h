#pragma once
#include "SFML/Graphics.hpp"

class Program
{
private:
	// TODO: Use references for most of these (floats especially)
	static float* deltaTime;
	static sf::RenderWindow* window;
	static float* mouseDelta;

public:
	// TODO: Don't write in H
	// TODO: Make a singleton or something idk
	static void Init(float* deltaTimePointer, sf::RenderWindow* renderWindowPointer, float* mouseDeltaPointer)
	{
		// Assign the pointers so every 'thing' doesn't have have
		// them all manually passed (annoying (waste of time))
		deltaTime = deltaTimePointer;
		window = renderWindowPointer;
		mouseDelta = mouseDeltaPointer;
	}

	static float* GetDeltaTime()
	{
		return deltaTime;
	}

	static sf::RenderWindow* GetWindow()
	{
		return window;
	}

	// TODO: Put in a custom Input class or something
	static float* GetMouseDelta()
	{
		return mouseDelta;
	}
};