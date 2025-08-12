#include "dialogueHandler.h"

bool DialogueHandler::ConfirmSaveMessageBox()
{
	int result = MessageBox(
		Utils::GetWindow()->getNativeHandle(),
		L"surely you're saving rn",
		L"erhm",
		MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2
	);

	return result == IDYES;
}

sf::Color DialogueHandler::LaunchColorPicker(sf::Color previousColor)
{
	// The resultant color thing
	CHOOSECOLOR colorPicker;

	// All of the sfml default colors
	// TODO: Maybe don't put here
	static COLORREF presetColors[10] = {
		Utils::sfmlColorToWin32(sf::Color::White),
		Utils::sfmlColorToWin32(sf::Color::Black),
		Utils::sfmlColorToWin32(sf::Color::Blue),
		Utils::sfmlColorToWin32(sf::Color::Cyan),
		Utils::sfmlColorToWin32(sf::Color::Green),
		Utils::sfmlColorToWin32(sf::Color::Cyan),
		Utils::sfmlColorToWin32(sf::Color::Green),
		Utils::sfmlColorToWin32(sf::Color::Magenta),
		Utils::sfmlColorToWin32(sf::Color::Red),
		Utils::sfmlColorToWin32(sf::Color::Yellow)
	};

	// Allocate space for the color picker or something
	ZeroMemory(&colorPicker, sizeof(colorPicker));
	colorPicker.lStructSize = sizeof(colorPicker);
	
	// Set the default color to be whatever our previous
	// color was, and add all the default SFML colors
	colorPicker.lpCustColors = presetColors;
	colorPicker.rgbResult = Utils::sfmlColorToWin32(previousColor);
	
	// Make it a part of this window, and let us make any color
	colorPicker.hwndOwner = Utils::GetWindow()->getNativeHandle();
	colorPicker.Flags = CC_FULLOPEN | CC_RGBINIT | CC_ANYCOLOR | CC_PREVENTFULLOPEN;

	// Return the selected color, otherwise whatever the previous one was
	if (ChooseColor(&colorPicker)) return previousColor;
	return Utils::Win32ColorToSfml(colorPicker.rgbResult);
}