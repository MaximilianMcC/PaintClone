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
	bool previouslyHovered = false;

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

	void SetBackgroundColor(sf::Color newColor);
	void SetPosition(sf::Vector2f newPosition);

	sf::Vector2f GetSize();
};