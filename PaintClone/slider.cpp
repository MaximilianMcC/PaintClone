#include "slider.h"

Slider::Slider() { }
Slider::Slider(float* percentagePointer, sf::Vector2f position, float lineLength, std::string labelText)
{
	// Make the background line thing
	line = sf::RectangleShape(sf::Vector2f(lineLength, 5.0f));
	line.setFillColor(Colors::Theme.UiBackground);
	line.setPosition(position);

	// Make the handle thing
	handle = sf::CircleShape(line.getSize().y * 1.3f);
	handle.setOrigin(sf::Vector2f(handle.getRadius(), line.getSize().y));
	handle.setFillColor(Colors::Theme.Foreground);
	SetPercentage(0.0f);

	// Make the hitbox (slightly larger than the actual line (Y))
	float padding = line.getSize().y * 3.0f;
	hitbox = sf::RectangleShape(line.getSize() + sf::Vector2f(0.0f, padding * 2.0f));
	hitbox.setOrigin(sf::Vector2f(0.0f, hitbox.getSize().y / 2.0f));
	hitbox.setPosition(position);

	// Make the label text
	label.emplace(*AssetManager::GetFont("arial"), labelText, 16u);
	label->setPosition(position - sf::Vector2f(0, 20.0f));
	label->setFillColor(Colors::Theme.Foreground);

	// Set the percentage pointer so we do not
	// need to call a grillion getters to use it
	percentage = percentagePointer;
	SetPercentage(*percentage);
}

void Slider::SetPercentage(float newPercentage)
{
	// Update the actual percentage
	*percentage = newPercentage;
	
	// Set the visual position to represent the
	// percentage visually as in a virual form
	// so we can visually see it visually
	// TODO: Don't do this weirdo formatting
	handle.setPosition(
		line.getPosition() +
		sf::Vector2f(line.getSize().x * *percentage, 0.0f)
	);
}

void Slider::Update()
{
	// Check for if we're clicking
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false) return;
	sf::Vector2f mousePosition = Utils::GetMousePosition();

	// Check for if we've clicked on the slider
	if (hitbox.getGlobalBounds().contains(mousePosition))
	{
		// Get the X distance away from the lines origin
		// and use that to calculate what percenage we are
		float xDistance = mousePosition.x - line.getPosition().x;
		float newPercentage = xDistance / line.getSize().x;

		// Update the handle thingy and actual percentage value
		SetPercentage(newPercentage);
	}
}

void Slider::Draw()
{
	Utils::GetWindow()->draw(line);
	Utils::GetWindow()->draw(handle);
	Utils::GetWindow()->draw(*label);
}

float Slider::GetPercentage()
{
	return *percentage;
}