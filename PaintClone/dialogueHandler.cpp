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
	// TODO: Maybe don't define this here
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
	if (ChooseColor(&colorPicker) == false) return previousColor;
	return Utils::Win32ColorToSfml(colorPicker.rgbResult);
}

//? the A on the end means it uses ascii
//? Not using a std::string so we dont lose it when returning
OPENFILENAMEA DialogueHandler::MakeFileDialogue(const char* title)
{
	// Allocate space for the dialogue
	OPENFILENAMEA fileDialogue;
	ZeroMemory(&fileDialogue, sizeof(fileDialogue));
	fileDialogue.lStructSize = sizeof(fileDialogue);

	// Link the window to us
	fileDialogue.hwndOwner = Utils::GetWindow()->getNativeHandle();

	// Set the title
	fileDialogue.lpstrTitle = title;

	// Get the path to the default photos directory
	//? static means it stays inside the object once returned
	static char defaultPath[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_MYPICTURES, NULL, 0, defaultPath);

	// Set the default filename
	strcat_s(defaultPath, "\\MyPicture.png");

	// Set the default path
	fileDialogue.lpstrFile = defaultPath;
	fileDialogue.nMaxFile = MAX_PATH;

	// Make and set the filter things
	fileDialogue.lpstrFilter =
		"Anything\0*.*\0"
		"Images and whatnot\0*.png;*.jpg;*.jpeg;*.bmp\0"
		"\0";
	fileDialogue.nFilterIndex = 2;

	// set the dialogues display/settings flags
	fileDialogue.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

	// Give back the dialogue
	return fileDialogue;
}

std::string DialogueHandler::LaunchSaveFileDialogue()
{	
	// Make the dialogue
	OPENFILENAMEA fileDialogue = MakeFileDialogue("Where are we saving the file rn");

	// Return the selected path, otherwise an empty string
	if (GetSaveFileNameA(&fileDialogue)) return std::string(fileDialogue.lpstrFile);
	return "";
}

std::string DialogueHandler::LaunchOpenFileDialogue()
{	
	// Make the dialogue
	OPENFILENAMEA fileDialogue = MakeFileDialogue("Where are we loading the file from rn");

	// Return the selected path, otherwise an empty string
	if (GetOpenFileNameA(&fileDialogue)) return std::string(fileDialogue.lpstrFile);
	return "";
}