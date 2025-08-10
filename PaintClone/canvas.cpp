#include "canvas.h"

Canvas::Canvas()
{
	Start();
}

void Canvas::Start()
{
	// Default canvas size
	canvasSize = sf::Vector2f(1920, 1440);
	
	// Camera setup (so we can pan and zoom & whatnot)
	camera.setSize(canvasSize);
	camera.setCenter(canvasSize / 2.0f);

	// Make the canvas render texture and sprite
	renderTexture = sf::RenderTexture(static_cast<sf::Vector2u>(canvasSize));
	sprite = sf::Sprite(renderTexture.getTexture());

	// Place the canvas in the centre of the canvas camera
	// sprite->setOrigin(camera.getCenter());
	// sprite->setPosition(static_cast<sf::Vector2f>(Utils::GetWindow()->getSize()) / 2.0f);

	// Make the background render texture and sprite
	transparentRenderTexture = sf::RenderTexture(renderTexture.getSize());
	transparentSprite = sf::Sprite(transparentRenderTexture.getTexture());

	//! debug
	renderTexture.clear(sf::Color::White);
	RegenerateAndUpdateDynamicCanvasTransparentBackgroundSpriteGridPattern();
	renderTexture.display();
}

void Canvas::Draw()
{
	// Switch to drawing with the canvases camera
	sf::View previousView = Utils::GetWindow()->getView();
	Utils::GetWindow()->setView(camera);
	{
		Utils::GetWindow()->draw(*transparentSprite);
		Utils::GetWindow()->draw(*sprite);
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
	if (sprite->getGlobalBounds().contains(position) == false) return false;

	// Account for the offset to find the actual position
	position = Utils::GetWindow()->mapPixelToCoords(static_cast<sf::Vector2i>(position));
	position -= sprite->getPosition() - sprite->getOrigin();

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
		moveSpeed * yDelta
	));
}

sf::RenderTexture* Canvas::GetRenderTexture()
{
	return &renderTexture;
};

// TODO: Call this every time we resize
// TODO: Only call this if its visible? 
// TODO: Maybe just make this edit a private render texture or something
// TODO: Just generate once (window size) then scissor to cut a hole in the canvas to show through
void Canvas::RegenerateAndUpdateDynamicCanvasTransparentBackgroundSpriteGridPattern()
{
	// The size of a square should always be 5% of the width of the screen
	// TODO: Maybe hardcode for specific monitor sizes?
	const float screenSizeToPixelRatio = 0.05f;
	sf::Vector2u screenSize = sf::VideoMode::getDesktopMode().size;
	sf::Vector2f squareSize = sf::Vector2f(
		(float)screenSize.x * screenSizeToPixelRatio,
		(float)screenSize.x * screenSizeToPixelRatio
	);

	// Figure out how many rows/columns are needed
	const int rows = (int)(canvasSize.x / squareSize.x);
	const int columns = (int)(canvasSize.y / squareSize.y);

	// The two colors to use for transparency
	// TODO: Dark/light theme alternatives
	sf::Color evenColor = sf::Color(0xffffffFF);
	sf::Color oddColor = sf::Color(0xcacacaFF);

	// Make the square cube thingy we're
	// gonna use to draw the pattern
	sf::RectangleShape square = sf::RectangleShape();
	square.setSize(squareSize);

	// Draw the pattern
	for (int y = 0; y < columns; y++)
	{
		for (int x = 0; x < rows; x++)
		{
			// Set the correct color
			sf::Color &color = ((x + y) % 2 == 0) ? evenColor : oddColor;
			square.setFillColor(color);

			// Set the new position
			square.setPosition(sf::Vector2f(
				x * squareSize.x,
				y * squareSize.y
			));

			// Draw the little square thingy
			transparentRenderTexture.draw(square);
		}
	}

	// 'Bake' the pattern, and chuck it on a texture
	// TODO: Don't make a new sprite every time. Just change texture
	// transparentRenderTexture.display();
	// transparentSprite->setTexture(transparentRenderTexture.getTexture());
}