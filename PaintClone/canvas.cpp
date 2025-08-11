#include "canvas.h"

Canvas::Canvas()
{
	Start();
}

void Canvas::Start()
{
	// Default canvas size
	canvasSize = sf::Vector2f(1920, 1080);
	
	// Camera setup (so we can pan and zoom & whatnot)
	camera.setSize(canvasSize);
	camera.setCenter(canvasSize / 2.0f);

	// Make the canvas render texture and sprite
	displayRenderTexture = sf::RenderTexture(static_cast<sf::Vector2u>(canvasSize));
	displaySprite = sf::Sprite(displayRenderTexture.getTexture());
	displaySprite->setScale(sf::Vector2f(1.0f, 1.0f));

	// Make the working render texture so the tools can draw on it
	workingRenderTexture = sf::RenderTexture(displayRenderTexture.getSize());
	workingSprite = sf::Sprite(workingRenderTexture.getTexture());

	// Add a default background color
	displayRenderTexture.clear(sf::Color::White);
	displayRenderTexture.display();

	// Sharing is caring
	Utils::SetCanvas(this);
	Utils::SetWorkingCanvas(this);
}

void Canvas::Draw()
{
	// Switch to drawing with the canvases camera
	sf::View previousView = Utils::GetWindow()->getView();
	Utils::GetWindow()->setView(camera);
	{
		Utils::GetWindow()->draw(*displaySprite);
		Utils::GetWindow()->draw(*workingSprite);
	}
	// Return to the 'normal' camera
	Utils::GetWindow()->setView(previousView);
}

// TODO: Don't put event definitions in the if statement
void Canvas::HandleEvent(sf::Event& event)
{
	// Check for if we've scrolled
	if (const sf::Event::MouseWheelScrolled* mouseEvent = event.getIf<sf::Event::MouseWheelScrolled>())
	{
		// Get the scrolls delta
		const float delta = mouseEvent->delta;

		// Hold alt while scrolling to zoom
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt)) Zoom(delta);

		// ctrl to horizontally scroll/pan
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) Pan(delta, 0);

		// Normal zoom to vertically scroll/pan
		else Pan(0, delta);
	}
}


//? & is a fake c# out variable
// Get the mouse position relative to the canvas (output sprite)
bool Canvas::GetMousePosition(sf::Vector2f& position)
{
	// Get the mouse position as a vector2
	position = Utils::GetMousePosition();

	// Ensure the mouse is actually over the canvas
	if (displaySprite->getGlobalBounds().contains(position) == false) return false;

	// Account for the offset to find the actual position
	position = Utils::GetWindow()->mapPixelToCoords(static_cast<sf::Vector2i>(position), camera);
	position -= displaySprite->getPosition() - displaySprite->getOrigin();

	return true;
}

void Canvas::Zoom(float delta)
{
	// Calculate if we wanna zoom in/out
	float zoom = 1.1f;
	if (delta > 0) zoom = 1.0f / zoom;

	// Actualyl zoom
	sf::Vector2f previousScale = camera.getSize();
	camera.zoom(zoom);

	// Ensure you can never zoom to the negatives (will flip the canvas (bad))
	if ((int)camera.getSize().x <= 0) camera.setSize(previousScale);
}

void Canvas::Pan(float xDelta, float yDelta)
{
	const float moveSpeed = 60.0f;
	camera.move(sf::Vector2f(
		moveSpeed * -xDelta,
		moveSpeed * -yDelta
	));
}

sf::RenderTexture* Canvas::GetRenderTexture()
{
	return &displayRenderTexture;
};

// Copy the contents of the working render texture to the display one
// then update the display sprite (so we can see it)
void Canvas::Bake()
{
	displayRenderTexture.display();
}