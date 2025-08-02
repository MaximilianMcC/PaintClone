#include "imageButton.h"

ImageButton::ImageButton(std::string imageKey, sf::Vector2f size, sf::Vector2f position)
: Button(size, position, sf::Color::Transparent)
{
	// Load the image sprite thingy
	image = sf::Sprite(*AssetManager::GetTexture(imageKey));

	// Set it to be the same as the 'normal' button
	image->setPosition(shape.getPosition());
	image->setScale(sf::Vector2(
		//? sfml try not to overcomplicate everything challenge (impossible)
		shape.getSize().x / image->getLocalBounds().size.x,
		shape.getSize().y / image->getLocalBounds().size.y
	));
}

void ImageButton::Draw()
{
	Program::GetWindow()->draw(*image);
}