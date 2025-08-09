#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "utils.h"
#include "colors.h"

// Things
#include "canvas.h"
#include "toolbar.h"


// TODO: Don't f2 rename types (cpp issue (breaks everything))
// TODO: Use const where applicable. Methods and whatnot idk
int main()
{
	// Load fonts and set the default color theme
	AssetManager::LoadDefaultFont("arial", "Arial");
	Colors::Theme = Colors::Dark;

	// Setup the SFML window
	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(854, 480)), "Paitning rn");
	window.setIcon(*AssetManager::LoadAndGetImage("icon", "./assets/icon.png"));
	bool debug = true;

	// Delta time setup
	float deltaTime = 0.0f;
	sf::Clock deltaTimeClock = sf::Clock();

	// Fps setup
	float fps = 0.0f;
	sf::Text fpsCounter = sf::Text(*AssetManager::GetFont("arial"));

	// Share data with whoever's keen
	Utils::Init(&deltaTime, &window);

	// Load/register everything
	// TODO: Most of these should probably be static but its worth it for `Thing`
	// TODO: Use unique pointers (heaps safer)
	std::vector<Thing*> things;
	things.push_back(new Canvas());
	things.push_back(new Toolbar());

	// TODO: Don't harcode
	// TODO: Do another way
	Utils::SetCanvas(static_cast<Canvas*>(things[0]));

	// Main program loop
	while (window.isOpen())
	{
		// Calculate delta time and fps
		//? Since a pointer was given we don't need to bother updating it
		deltaTime = deltaTimeClock.restart().asSeconds();
		fps = 1 / deltaTime;
		fpsCounter.setString(std::to_string((int)fps) + " fps");

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

		// Check for if we wanna toggle debug mode
		// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Grave)) debug = !debug;

		// Update everything
		{
			for (Thing* thing : things) thing->Update();
		}

		// Draw everything
		window.clear();
		{
			for (Thing* thing : things) thing->Draw();
		}
		if (debug) window.draw(fpsCounter);
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