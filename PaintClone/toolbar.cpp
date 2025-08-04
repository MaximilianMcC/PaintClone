#include "toolbar.h"
#include "cursorTool.h"

Toolbar::Toolbar()
{
	Start();
}

void Toolbar::Start()
{
	// The 'size' of a toolbar is x% of the screen size
	//? idk what percentage it actually is (bad at maths)
	// TODO: No magic numbers
	sf::Vector2u screenSize = sf::VideoMode::getDesktopMode().size;
	float size = screenSize.x / 30.0f;

	// Horizontal
	toolSettings = sf::RectangleShape(sf::Vector2(0.0f, size));

	// The vertical one is spawned beneath the settings one
	toolSelector = sf::RectangleShape(sf::Vector2(size, 0.0f));
	toolSelector.setPosition(sf::Vector2(0.0f, size));

	// Set the colors
	// TODO: Color themes
	toolSettings.setFillColor(sf::Color(0x222222FF)); // Darker gray
	toolSelector.setFillColor(sf::Color(0x333333FF)); // Dark gray

	// Set their initial dynamic sizes
	ResizeUi();


	
	
	// Make all the buttons
	// TODO: Put in another function
	{
		// Make the tool
		CursorTool* cursorTool = new CursorTool("Cursor", "hi");
		ImageButton* cursorButton = new ImageButton("./assets/cursor.png", sf::Vector2f(120.0f, 100.0f), sf::Vector2f(10.0f, 10.0f), sf::Keyboard::Key::V);
		cursorButton->SetCallback(SetTool(cursorTool));

		// Make coppies of the two things and
		// place them in the lists
		uiElements.push_back(cursorButton);
		tools.push_back(cursorTool);

		// By default the cursor tool is the current one
		//? only kinda acceptable to use [0] here idk
		// TODO: Don't hardcode index and do this
		//! fix rn (bad)
		currentTool = tools[0];
	}

}
std::function<void()> Toolbar::SetTool(Tool* tool)
{
	// Give back the lambda function to change the tool
	return [this, tool]()
	{
		// Deselect the current tool
		currentTool->Deselect();

		// Select the new tool
		currentTool = tool;
		currentTool->Select();
	};
}

void Toolbar::HandleEvent(sf::Event& event)
{
	// Resize the ui to accompany the window
	if (event.is<sf::Event::Resized>()) ResizeUi();
}

// Make the ui elements fit the screen size properly
//? called whenever the screen is resized (event ig)
void Toolbar::ResizeUi()
{
	// Get the new window size
	sf::Vector2u windowSize = Program::GetWindow()->getSize();

	// The top one's width is the same as the window
	toolSettings.setSize(sf::Vector2f(
		(float)windowSize.x,
		toolSettings.getSize().y)
	);

	// The side ones height is the same as the window
	toolSelector.setSize(sf::Vector2f(
		toolSelector.getSize().x,
		(float)windowSize.y
	));
}

void Toolbar::Update()
{
	// Update all the ui elements
	for (UiElement* uiElement : uiElements) uiElement->Update();

	// Update the selected tool
	currentTool->Update();
}

void Toolbar::Draw()
{
	// Draw the background ui things
	Program::GetWindow()->draw(toolSelector);
	Program::GetWindow()->draw(toolSettings);

	// Draw all the ui elements
	for (UiElement* uiElement : uiElements) uiElement->Draw();

	// Draw the selected tool
	currentTool->Draw();
}

void Toolbar::CleanUp()
{
	// Get rid of all the dynamically added ui elements
	for (UiElement* uiElement : uiElements)
	{
		delete uiElement;
		uiElement = nullptr;
	}
	uiElements.clear();

	// Get rid of all the dynamically added tools
	for (Tool* tool : tools)
	{
		delete tool;
		tool = nullptr;
	}
	tools.clear();
}