#pragma once	
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "canvas.h"
#include "program.h"

// TODO: Don't f2 rename types (cpp issue (breaks everything))

int main()
{
	// Setup the SFML window
	sf::RenderWindow window(sf::VideoMode({ 600, 500 }), "Paitning rn");

	// Delta time setup
	float deltaTime = 0.0f;
	sf::Clock deltaTimeClock = sf::Clock();

	// Share data with whoever's keen
	Program::Init(&deltaTime, &window);

	// Load/register everything
	// TODO: Most of these should probably be static but its worth it for `Thing`
	// std::vector<Thing> things;
	Canvas temp = Canvas();
	// things.push_back(temp);

	// Main program loop
	while (window.isOpen())
	{
		// Check for events
		while (const std::optional event = window.pollEvent())
		{
			// Check for if we wanna close the window
			if (event->is<sf::Event::Closed>()) window.close();
		}

		// Calculate delta time
		//? Since a pointer was given we don't need to bother updating it
		deltaTime = deltaTimeClock.restart().asSeconds();

		// Update everything
		{
			// for (int i = 0; i < things.size(); i++) things[i].Update();
			temp.Update();
		}

		// Draw everything
		window.clear();
		{
			// for (int i = 0; i < things.size(); i++) things[i].Draw();
			temp.Draw();
		}
		window.display();
	}

	return 0;
}