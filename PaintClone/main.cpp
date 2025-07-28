#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "program.h"

// Things
#include "canvas.h"
#include "toolbar.h"

// TODO: Don't f2 rename types (cpp issue (breaks everything))

// TODO: Use const where applicable. Methods and whatnot idk
int main()
{
	// Setup the SFML window
	sf::RenderWindow window(sf::VideoMode({ 600, 500 }), "Paitning rn");

	// Delta time setup
	float deltaTime = 0.0f;
	sf::Clock deltaTimeClock = sf::Clock();

	// sfml events system is stink so doing this
	float mouseDelta = 0.0f;

	// Share data with whoever's keen
	Program::Init(&deltaTime, &window, &mouseDelta);

	// Load/register everything
	// TODO: Most of these should probably be static but its worth it for `Thing`
	// TODO: Use unique pointers (heaps safer)
	std::vector<Thing*> things;
	things.push_back(new Canvas());
	things.push_back(new Toolbar());

	// Main program loop
	while (window.isOpen())
	{
		// Clear the old events, and check for any new events
		while (const std::optional event = window.pollEvent())
		{
			// Check for if we wanna close the window
			if (event->is<sf::Event::Closed>()) window.close();

			// Check for if we scrolled
			if (const sf::Event::MouseWheelScrolled* mouseEvent = event->getIf<sf::Event::MouseWheelScrolled>())
			{
				// Only interested in vertical scrolling because I lowk never seen a horizontal mouse
				if (mouseEvent->wheel != sf::Mouse::Wheel::Vertical) continue;

				// Store the event
				mouseDelta = mouseEvent->delta;
			}
			else mouseDelta = 0;
		}

		// Calculate delta time
		//? Since a pointer was given we don't need to bother updating it
		deltaTime = deltaTimeClock.restart().asSeconds();
		// std::cout << *Program::GetDeltaTime() << std::endl;

		// Update everything
		{
			for (Thing* thing : things) thing->Update();
		}

		// Draw everything
		window.clear();
		{
			for (Thing* thing : things) thing->Draw();
		}
		window.display();
	}

	// Be a tidy kiwi
	for (Thing* thing : things)
	{
		thing->CleanUp();
		delete thing;
	}

	return 0;
}