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
	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(854, 480)), "Paitning rn");
	window.setIcon(*AssetManager::LoadAndGetImage("icon", "./assets/icon.png"));

	// Delta time setup
	float deltaTime = 0.0f;
	sf::Clock deltaTimeClock = sf::Clock();

	// Share data with whoever's keen
	Program::Init(&deltaTime, &window);

	// Load/register everything
	// TODO: Most of these should probably be static but its worth it for `Thing`
	// TODO: Use unique pointers (heaps safer)
	std::vector<Thing*> things;
	things.push_back(new Canvas());
	things.push_back(new Toolbar());

	// Load a font
	AssetManager::LoadDefaultFont("arial", "Arial");

	// Main program loop
	while (window.isOpen())
	{
		// Calculate delta time
		//? Since a pointer was given we don't need to bother updating it
		deltaTime = deltaTimeClock.restart().asSeconds();

		// Check for new events
		while (const std::optional event = window.pollEvent())
		{
			// Check for if we wanna close the window
			if (event->is<sf::Event::Closed>())
			{
				window.close();
				continue;
			}

			// Check for if we wanna resize the window
			if (const sf::Event::Resized* resize = event->getIf<sf::Event::Resized>())
			{
				// Get the size that we want the window to be
				sf::Vector2f newSize = static_cast<sf::Vector2f>(resize->size);
				sf::FloatRect newWindowSize(sf::Vector2f(0.0f, 0.0f), newSize);

				// Don't stretch the window by changing its camera size
				window.setView(sf::View(newWindowSize));
			}

			// Extract the 'pure' event, then send it to
			// all things to use (not a fan of std::optional)
			sf::Event currentEvent = event.value();

			// Send all other events through to all things
			for (Thing* thing : things) thing->HandleEvent(currentEvent);
		}

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
		thing = nullptr;
	}

	return 0;
}