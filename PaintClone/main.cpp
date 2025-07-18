#include <SFML/Graphics.hpp>
#include <iostream>
#include "canvas.h"

int main()
{
	// Setup the SFML window
    sf::RenderWindow window(sf::VideoMode({ 600, 500 }), "Paitning rn");

    // Delta time setup
    float deltaTime = 0.0f;
	sf::Clock deltaTimeClock = sf::Clock();

	// Make the canvas
    // TODO: Don't do like this
	Canvas canvas = Canvas();

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
		deltaTime = deltaTimeClock.restart().asSeconds();
		//std::cout << "Delta Time: " << deltaTime << std::endl;

        // Update
        {
            canvas.TempUpdate(window);
        }

        // Draw
        window.clear();
        {
			canvas.Draw(window);
        }
        window.display();
    }
}