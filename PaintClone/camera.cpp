#include "camera.h"

Camera::Camera(sf::Vector2f outputViewSize)
{
    // Create the actual camera
	SetSizeAndMakeView(outputViewSize);

    // Create the sprite so we can render it
    outputSprite = sf::Sprite(view.getTexture());
}

void Camera::SetSizeAndMakeView(sf::Vector2f newSize)
{
	// Save our current size
	size = newSize;

	// Make a new render texture with this size
	sf::Vector2u textureSize = static_cast<sf::Vector2u>(size);
    view = sf::RenderTexture(textureSize);
}
