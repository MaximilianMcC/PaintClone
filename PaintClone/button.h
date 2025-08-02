#pragma once
#include "thing.h"

class Button : public UiElement
{
protected:
    sf::RectangleShape shape;
    
    // TODO: Don't set every frame
    bool clicked = false;
    bool previouslyClicked = false;
    bool hovered = false;

public:
    Button(sf::Vector2f size, sf::Vector2f position, sf::Color backgroundColor);

    void Update() override;
    void Draw() override;

    bool IsClicked();
    bool IsHeld();
    bool IsHovered();
};