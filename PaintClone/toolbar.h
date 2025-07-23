#pragma once
#include "thing.h"

class Toolbar : public Thing
{
private:
	sf::RectangleShape background;
public:
	void Start() override;
	void Update(float deltaTime, sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) override;

	sf::RectangleShape GetBackground()
	{
		return background;
	}
};