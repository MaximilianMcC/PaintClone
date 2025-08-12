#include "colorPicker.h"
#include "toolbar.h"

ColorPicker::ColorPicker()
{
	Start();
}

void ColorPicker::Start()
{
	Utils::SetColorPicker(this);

	// Make the fill color button
	fillColorButton = new Button(LayoutInfo::ButtonSize, sf::Vector2f(), fillColor, sf::Keyboard::Key::L);
	fillColorButton->SetCallback(Pick(fillColorButton, &fillColor));

	// Make the outline color button
	outlineColorButton = new Button(LayoutInfo::ButtonSize, sf::Vector2f(), outlineColor, sf::Keyboard::Key::O);
	outlineColorButton->SetCallback(Pick(outlineColorButton, &outlineColor));

	ResizeUi();
}

void ColorPicker::Update()
{
	fillColorButton->Update();
	outlineColorButton->Update();
}

void ColorPicker::HandleEvent(sf::Event &event)
{
	// Check for if we've resized the window
	if (event.is<sf::Event::Resized>() == false) ResizeUi();
}

void ColorPicker::ResizeUi()
{
	// Get the new window size
	float windowHeight = (float)Utils::GetWindow()->getSize().y;

	// Get the position of the bottom most button
	sf::Vector2f position = sf::Vector2f(
		LayoutInfo::Padding,
		windowHeight - LayoutInfo::Padding - LayoutInfo::ButtonSize.y - LayoutInfo::Padding
	);

	// Outline color is on the bottom
	outlineColorButton->SetPosition(position);
	position.y -= LayoutInfo::Padding + LayoutInfo::ButtonSize.y;

	// Fill color is on top
	fillColorButton->SetPosition(position);
}

void ColorPicker::Draw()
{
	// Render the buttons
	fillColorButton->Draw();
	outlineColorButton->Draw();
}

std::function<void()> ColorPicker::Pick(Button* colorPickerButton, sf::Color* colorToPick)
{
	return [this, colorPickerButton, colorToPick]()
	{
		// Get, then set the new color
		sf::Color newColor = DialogueHandler::LaunchColorPicker(*colorToPick);
		*colorToPick = newColor;

		// Update the buttons color
		colorPickerButton->SetBackgroundColor(newColor);
	};
}

void ColorPicker::CleanUp()
{
	delete fillColorButton;
	fillColorButton = nullptr;

	delete outlineColorButton;
	outlineColorButton = nullptr;
}

sf::Color ColorPicker::GetFillColor()
{
	return fillColor;
}

sf::Color ColorPicker::GetOutlineColor()
{
	return outlineColor;
}
