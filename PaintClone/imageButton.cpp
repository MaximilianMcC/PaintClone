#include "imageButton.h"

ImageButton::ImageButton(std::string imagePath, sf::Vector2f size, sf::Vector2f position, sf::Keyboard::Key shortcutKey)
: Button(size, position, Colors::Theme.BackgroundDark, shortcutKey)
{
	// Load a new texture and set it as our image
	//? Using the texture path as the key because its unique
	texture = sf::Sprite(*AssetManager::LoadAndGetTexture(imagePath, imagePath));

	// TODO: Don't rewrite (put in method)
	// Set it to be the same as the 'normal' button
	texture->setPosition(shape.getPosition());
	texture->setScale(sf::Vector2(
		//? sfml try not to overcomplicate everything challenge (impossible)
		shape.getSize().x / texture->getLocalBounds().size.x,
		shape.getSize().y / texture->getLocalBounds().size.y
	));
}

ImageButton::ImageButton(sf::Texture* image, sf::Vector2f size, sf::Vector2f position, sf::Keyboard::Key shortcutKey)
: Button(size, position, Colors::Theme.BackgroundDark, shortcutKey)
{
	// Load the image sprite thingy
	texture = sf::Sprite(*image);

	// TODO: Don't rewrite (put in method)
	// Set it to be the same as the 'normal' button
	texture->setPosition(shape.getPosition());
	texture->setScale(sf::Vector2(
		//? sfml try not to overcomplicate everything challenge (impossible)
		shape.getSize().x / texture->getLocalBounds().size.x,
		shape.getSize().y / texture->getLocalBounds().size.y
	));
}

void ImageButton::Draw()
{
	// Draw the background fill color
	// TODO: Make this optional (turn it off)
	Utils::GetWindow()->draw(shape);

	// Draw the actual image
	Utils::GetWindow()->draw(*texture);
}