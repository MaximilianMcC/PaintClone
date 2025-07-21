#include "canvas.h"

//? cpp you gotta redefine static things for some reason
sf::Vector2u Canvas::size;
sf::RenderTexture Canvas::renderTexture;

void Canvas::Start()
{
	SetSize(100, 100);
	renderTexture = sf::RenderTexture(GetSize());
}

void Canvas::Update(float deltaTime, sf::RenderWindow& window)
{
	float bruhSize = 30;
	sf::Color bruhColor = sf::Color::Black;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		// Get the mouse position relative to the window
		// TODO: Make it relative to the canvas
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		// We wanna start drawing from the centre, not top left
		sf::Vector2f strokePosition = static_cast<sf::Vector2f>(mousePosition);
		strokePosition -= sf::Vector2f(bruhSize, bruhSize);

		// Make the brush stroke
		sf::CircleShape stroke(bruhSize);
		stroke.setFillColor(bruhColor);
		stroke.setPosition(strokePosition);

		// Draw it onto the canvas
		renderTexture.draw(stroke);
		renderTexture.display();
	}
}

void Canvas::Draw(sf::RenderWindow& window)
{
	// Turn the render texture into a sprite so we can draw it
	sf::Texture canvas = renderTexture.getTexture();
	sf::Sprite canvasSprite(canvas);

	// Draw it
	window.draw(canvasSprite);
}