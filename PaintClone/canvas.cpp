#include "canvas.h"

Canvas::Canvas()
{
	Start();
}

void Canvas::Start()
{
	// The size of the default canvas is 1920x1080
	// TODO: Make it so you can change this in the settings
	size = sf::Vector2f(1920, 1080);
	sf::Vector2u canvasSize = static_cast<sf::Vector2u>(size);

	// Set the transparent thingy to
	// be the same size as the canvas
	transparentRenderTexture = sf::RenderTexture(canvasSize);
	RegenerateAndUpdateDynamicCanvasTransparentBackgroundSpriteGridPattern();

	// Create the render texture so we can draw
	//? When you add layers, just draw in the correct order instead of multiple render textures
	renderTexture = sf::RenderTexture(canvasSize);
	renderTexture.display();
	
	// Make the sprite so we can actually render the render texture
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

// TODO: Don't put event definitions in the if statement
void Canvas::HandleEvent(sf::Event& event)
{
	// Check for if we've scrolled
	if (const sf::Event::MouseWheelScrolled* mouseEvent = event.getIf<sf::Event::MouseWheelScrolled>())
	{
		// Get the scrolls delta
		const float delta = mouseEvent->delta;
		Zoom(delta);
	}

	// Check for if we've resized
	if (event.is<sf::Event::Resized>())
	{

	}
}

void Canvas::Draw()
{
	// Draw the very bottom transparent thing
	Program::GetWindow()->draw(*transparentSprite);

	// Draw all the layers
	
	// Program::GetWindow()->draw(*outputSprite);
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

// TODO: Call this every time we resize
// TODO: Only call this if its visible? 
// TODO: Maybe just make this edit a private render texture or something
// TODO: Just generate once (window size) then scissor to cut a hole in the canvas to show through
void Canvas::RegenerateAndUpdateDynamicCanvasTransparentBackgroundSpriteGridPattern()
{
	// The size of a square should always be 5% of the width of the screen
	// TODO: Maybe hardcode for specific monitor sizes?
	float screenSizeToPixelRatio = 0.005f;
	sf::Vector2u screenSize = sf::VideoMode::getDesktopMode().size;
	sf::Vector2f squareSize = sf::Vector2f(
		(float)screenSize.x * screenSizeToPixelRatio,
		(float)screenSize.x * screenSizeToPixelRatio
	);

	// Figure out how many rows/columns are needed
	int rows = (int)(size.x / squareSize.x);
	int columns = (int)(size.y / squareSize.y);

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
	transparentRenderTexture.display();
	transparentSprite = sf::Sprite(transparentRenderTexture.getTexture());
	//? transparentSprite->setTexture(transparentRenderTexture.getTexture());
}




// TODO: Make a float for scale but idk its just like duplicated data
void Canvas::Zoom(float delta)
{
	// Get how much we're gonna zoom
	const float zoomMultiplier = 0.05f;
	const float zoom = delta * zoomMultiplier;
	const sf::Vector2f newZoom = outputSprite->getScale() + sf::Vector2f(zoom, zoom);

	// Resize the canvas to zoom
	outputSprite->setScale(newZoom);
	RegenerateAndUpdateDynamicCanvasTransparentBackgroundSpriteGridPattern();
}