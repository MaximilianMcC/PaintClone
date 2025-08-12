#include "lineTool.h"
#define PI 3.14159f 

void LineTool::Start()
{
	// Make the slider (settings)
	slider = Slider(&thickness, sf::Vector2f(30, 20), 200.0f, "erhm");
}

void LineTool::MakeNewShape()
{
	shape = std::make_unique<sf::RectangleShape>();
}

void LineTool::ResizeShape(sf::Vector2f newSize)
{
	// Get the rectangle as a line
	sf::RectangleShape* line = static_cast<sf::RectangleShape*>(shape.get());

	// Figure out what the length and angle
	// need to be based on the mouse position
	// TODO: Put this stuff in utils
	float length = sqrt((newSize.x * newSize.x) + (newSize.y * newSize.y));
	float angle = atan2(newSize.y, newSize.x);

	// Update the rectangle to make it a fake line
	line->setSize(sf::Vector2f(length, thickness * 20));
	line->setRotation(sf::radians(angle));
}

void LineTool::Update()
{
	slider.Update();
	ShapeTool::Update();
}

void LineTool::Draw()
{
	ShapeTool::Draw();
	slider.Draw();
}