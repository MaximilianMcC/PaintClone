#include "camera.h"

Camera::Camera(sf::Vector2f outputViewSize)
{
    // Create the actual camera
	SetSizeAndMakeView(outputViewSize);

    // Create the sprite so we can render it
    outputSprite = sf::Sprite(camera.getTexture());
}

void Camera::DrawOutput()
{
	// Draw the camera's output to the window
	Program::GetWindow()->draw(outputSprite);
}

void Camera::DrawToCamera(sf::Drawable* thingToDraw)
{
	// Draw the thing on the camera (render texture)
	camera.draw(*thingToDraw);
}

void Camera::SetZoom(float newZoom)
{
	// Trun the float into an int
	zoom = sf::Vector2f(newZoom, newZoom);
}

void Camera::AddZoom(float zoomToAdd)
{
	// Add the new suff onto the old stuff
	//? both zoom axis are the same so just using x is fine
	float newZoom = zoom.x + zoomToAdd;
	SetZoom(newZoom);
}

void Camera::SetPosition(sf::Vector2f newPosition)
{
	// I hate these rinky as getters and setters
	position = newPosition;
}

void Camera::SetTarget(sf::Vector2f newPosition)
{
	target = newPosition;
}

void Camera::SetTargetRenderOffset(sf::Vector2f newTargetRenderOffset)
{
	// TODO: Convert the 0.x into x yk (not dynamic)
	targetRenderOffset = newTargetRenderOffset;
}

void Camera::SetSizeAndMakeView(sf::Vector2f newSize)
{
	// Save our current size
	size = newSize;

	// Make a new render texture with this size
	sf::Vector2u textureSize = static_cast<sf::Vector2u>(size);
    camera = sf::RenderTexture(textureSize);
}
