#include "canvas.h"

Canvas::Canvas()
{
	Start();
}

void Canvas::Start()
{
	// Make the canvas 80% of the size of the window
	// TODO: Don't have this canvasBackground thing
	canvasBackground = sf::RectangleShape({
		Program::GetWindow()->getSize().x * 0.8f,
		Program::GetWindow()->getSize().y * 0.8f,
	});

	// Set a default background color
	// TODO: Set transparent with transparent grid in the back
	// TODO: Put colors and whatnot in enum
	canvasBackground.setFillColor(sf::Color(0xff00ffff));

	// Create the render texture so we can draw
	//? When you add layers, just draw in the correct order instead of multiple render textures
	sf::Vector2u canvasSize = static_cast<sf::Vector2u>(canvasBackground.getSize());
	renderTexture = sf::RenderTexture(canvasSize);
	
	//! debug
	renderTexture.draw(canvasBackground);

	// Make the sprite so we can actually render the render texture
	renderTexture.display();
	outputSprite = sf::Sprite(renderTexture.getTexture());

	// Figure out how much room we've for the canvas to
	// occupy, excluding the left and top bar ui things
	// TODO: Add ui
	sf::Vector2f availableSpace = static_cast<sf::Vector2f>(Program::GetWindow()->getSize());
	//! availableSpace.X -= leftToolBarSize.X;
	//! availableSpace.Y -= topToolBarSize.Y;
	
	// Set the origin to be in the centre
	// TODO: Just use maths (could be easier for panning/zooming)
	outputSprite->setOrigin(outputSprite->getLocalBounds().size / 2.0f);

	// Place the canvas in the centre by default
	renderPosition = availableSpace / 2.0f;
	outputSprite->setPosition(renderPosition);
}

void Canvas::Update()
{
	sf::Vector2f position;
	Program::GetWindow()->setTitle(GetMousePosition(position) ? "on" : "off");

	//! debug
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		// Get the position of the mouse
		sf::Vector2f position;
		if (GetMousePosition(position) == false) return;

		// Make the dot
		sf::CircleShape stroke = sf::CircleShape();
		stroke.setRadius(5);
		stroke.setOrigin({ 5.0f, 5.0f });
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
// Get the mouse position relative to the canvas (output sprite)
bool Canvas::GetMousePosition(sf::Vector2f& position)
{
	// Get the mouse position as a vector2
	sf::Vector2i rawPosition = sf::Mouse::getPosition(*Program::GetWindow());
	position = static_cast<sf::Vector2f>(rawPosition);

	// Ensure the mouse is actually over the canvas
	if (outputSprite->getGlobalBounds().contains(position) == false) return false;

	// Account for the offset to find the actual position
	position = Program::GetWindow()->mapPixelToCoords(rawPosition);
	position -= outputSprite->getPosition() - outputSprite->getOrigin();

	return true;
}