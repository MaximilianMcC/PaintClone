#include "imageButton.h"

ImageButton::ImageButton(std::string imagePath, sf::Vector2f size, sf::Vector2f position)
: Button(size, position, sf::Color::Transparent)
{
	// Use the pointer address to ourselves as the image key
	// TODO: Don't do this
	//! Probably really really bad
	std::string key = "button" + std::to_string((unsigned long)this);
	std::cout << key << std::endl;

	// Load a new texture and set it as our image
	texture = sf::Sprite(*AssetManager::LoadAndGetTexture(key, imagePath));

	// Set it to be the same as the 'normal' button
	texture->setPosition(shape.getPosition());
	texture->setScale(sf::Vector2(
		//? sfml try not to overcomplicate everything challenge (impossible)
		shape.getSize().x / texture->getLocalBounds().size.x,
		shape.getSize().y / texture->getLocalBounds().size.y
	));
}

ImageButton::ImageButton(sf::Texture* image, sf::Vector2f size, sf::Vector2f position)
: Button(size, position, sf::Color::Transparent)
{
	// Load the image sprite thingy
	texture = sf::Sprite(*image);

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
	Program::GetWindow()->draw(*texture);
}