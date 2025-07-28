#include "toolbar.h"

Toolbar::Toolbar()
{
	Start();
}

void Toolbar::Start()
{
	// The 'size' of a toolbar is 1/20th of the screen size
	// TODO: No magic numbers
	sf::Vector2u screenSize = sf::VideoMode::getDesktopMode().size;
	float size = screenSize.x / 20.0f;

	// Horizontal
	toolSettings = sf::RectangleShape(sf::Vector2(0.0f, size));

	// The vertical one is spawned beneath the settings one
	toolSelector = sf::RectangleShape(sf::Vector2(size, 0.0f));
	toolSelector.setPosition(sf::Vector2(0.0f, size));

	// Set the colors
	const sf::Color backgroundColor = sf::Color(0x333333FF);
	toolSettings.setFillColor(backgroundColor);
	toolSelector.setFillColor(backgroundColor);

	// Set their initial dynamic sizes
	ResizeUi();
}

void Toolbar::HandleEvent(sf::Event& event)
{
	// Resize the ui to accompany the window
	if (event.is<sf::Event::Resized>()) ResizeUi();
}

// Make the ui elements fit the screen size properly
//? called whenever the screen is resized (event ig)
void Toolbar::ResizeUi()
{
	// Get the new window size
	sf::Vector2u windowSize = Program::GetWindow()->getSize();

	// Set the horizontal one to be the entire screen width
	toolSelector.setSize(sf::Vector2f(toolSelector.getSize().x, windowSize.y));

	// Set the vertical thingy to be the entire
	// screen height, minus the top of the settings
	toolSettings.setSize(sf::Vector2f(toolSettings.getSize().x, windowSize.y - toolSelector.getSize().y));
}

void Toolbar::Draw()
{
	// Draw the background ui things
	Program::GetWindow()->draw(toolSelector);
	Program::GetWindow()->draw(toolSettings);
}