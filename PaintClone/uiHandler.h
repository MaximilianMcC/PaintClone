#pragma once
#include "thing.h"

class UiHandler : public Thing
{
private:
	
public:
	void Start() override;
	void Update(float deltaTime, sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) override
};