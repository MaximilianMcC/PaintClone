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

	// Set a default background color
	// TODO: Set transparent with transparent grid in the back
	// TODO: Put colors and whatnot in enum
	canvas.setFillColor(sf::Color(0xff00ffff));

	// Create the render texture so we can draw
	//? When you add layers, just draw in the correct order instead of multiple render textures
	sf::Vector2u canvasSize = static_cast<sf::Vector2u>(canvas.getSize());
	renderTexture = sf::RenderTexture(canvasSize);
	
	// Make the sprite so we can actually render the render texture
	renderTexture.display();
	outputSprite = sf::Sprite(renderTexture.getTexture());

	// Figure out how much room we've for the canvas to
	// occupy, excluding the left and top bar ui things
	// TODO: Add ui
	sf::Vector2f availableSpace = static_cast<sf::Vector2f>(Program::GetWindow()->getSize());
	//! availableSpace.X -= leftToolBarSize.X;
	//! availableSpace.Y -= topToolBarSize.Y;
	
	// Place the canvas in the centre by default/initially
	// TODO: Account for zoom → `outputSprite.setScale();`
	sf::Vector2f canvasSpawnPosition = (availableSpace - canvas.getSize()) / 2.0f;
	outputSprite->setPosition(canvasSpawnPosition);
}

void Canvas::Update()
{
	//! debug
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		// Get the position of the mouse
		sf::Vector2f position;
		if (GetMousePosition(position) == false) return;

		// Make the dot
		sf::CircleShape stroke = sf::CircleShape();
		stroke.setRadius(30);
		stroke.setPosition(position);

		// Draw the dot
		renderTexture.draw(stroke);
	}
}

void Canvas::Draw()
{
	// Draw the canvas
	Program::GetWindow()->draw(*outputSprite);
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