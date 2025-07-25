#include "canvas.h"

Canvas::Canvas()
{
	Start();
}

void Canvas::Start()
{
	// Make the canvas 80% of the size of the window
	float initialCanvasScaleFactor = 0.8f;
	sf::Vector2f windowSize = static_cast<sf::Vector2f>(Program::GetWindow()->getSize());
	size = windowSize * initialCanvasScaleFactor;

	// Create the render texture so we can draw
	//? When you add layers, just draw in the correct order instead of multiple render textures
	sf::Vector2u canvasSize = static_cast<sf::Vector2u>(size);
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

	

	// Draw a transparent background on the canvas
	// TODO: Don't do this here
	//! temp debug
	renderTexture.draw(*GenerateDynamicCanvasTransparentBackgroundSpriteGridPattern().sprite);
}

void Canvas::Update()
{
	// Check for if we'd like to zoom in
	std::cout << *Program::GetMouseDelta() << std::endl;
}

void Canvas::Draw()
{
	// Draw the canvas
	Program::GetWindow()->draw(*outputSprite);

	// Program::GetWindow()->draw(*GenerateDynamicCanvasTransparentBackgroundSpriteGridPattern().sprite);
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
SpriteWithTexture Canvas::GenerateDynamicCanvasTransparentBackgroundSpriteGridPattern()
{
	// Make a new render texture to draw on
	sf::Vector2u canvasSize = static_cast<sf::Vector2u>(size);
	sf::RenderTexture transparentRenderTexture = sf::RenderTexture(canvasSize);

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

	// 'Bake' the pattern
	transparentRenderTexture.display();

	// Chuck it in a struct so we can render it
	//? `emplace` calls the ctor of the sprite kinda
	SpriteWithTexture output;
	output.texture = transparentRenderTexture.getTexture();
	output.sprite.emplace(output.texture);

	// ka pai
	return output;
}