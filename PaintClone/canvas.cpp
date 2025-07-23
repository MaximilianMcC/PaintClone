#include "canvas.h"

Canvas::Canvas()
{
	Start();
}

void Canvas::Start()
{
	// Make the canvas 80% of the size of the window
	canvas = sf::RectangleShape({
		Program::GetWindow()->getSize().x * 0.8f,
		Program::GetWindow()->getSize().y * 0.8f,
	});
	renderTexture = sf::RenderTexture();
}

void Canvas::Update()
{
	//? temp
	float bruhSize = 30;
	sf::Color bruhColor = sf::Color::Black;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		// Get the mouse position relative to the window
		// TODO: Make it relative to the canvas
		// sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

		// We wanna start drawing from the centre, not top left
		// sf::Vector2f strokePosition = static_cast<sf::Vector2f>(mousePosition);
		// strokePosition -= sf::Vector2f(bruhSize, bruhSize);

		// Make the brush stroke
		// sf::CircleShape stroke(bruhSize);
		// stroke.setFillColor(bruhColor);
		// stroke.setPosition(strokePosition);

		// Draw it onto the canvas
		// renderTexture.draw(stroke);
		// renderTexture.display();
	}
}

void Canvas::Draw()
{
	// Turn the render texture into a sprite so we can draw it
	sf::Texture canvas = renderTexture.getTexture();
	sf::Sprite canvasSprite(canvas);

	// Draw it
	// window->draw(canvasSprite);
}

//? & is a fake c# out variable
bool Canvas::GetMousePosition(sf::Vector2f& position)
{
	// Get the mouse position as a vector2f
	sf::Vector2i rawPosition = sf::Mouse::getPosition(*Program::GetWindow());
	position = static_cast<sf::Vector2f>(rawPosition);

	// Check for if the mouse is over/on the canvas
	return canvas.getGlobalBounds().contains(position);
}