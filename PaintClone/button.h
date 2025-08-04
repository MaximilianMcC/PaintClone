#pragma once
#include "thing.h"

class Button : public UiElement
{
protected:
	sf::RectangleShape shape;
	sf::Keyboard::Key shortcut;
	
	// TODO: Don't set every frame
	bool clicked = false;
	bool previouslyClicked = false;
	bool hovered = false;

	std::function<void()> callbackFunction;

	void CheckForClicking();

public:
	Button(sf::Vector2f size, sf::Vector2f position, sf::Color backgroundColor, sf::Keyboard::Key shortcutKey = sf::Keyboard::Key::Unknown);
	void SetCallback(std::function<void()> methodToCall);

	void Update() override;
	void Draw() override;

	bool IsClicked();
	bool IsHeld();
	bool IsHovered();
};