#include "toolbar.h"
#include "cursorTool.h"
#include "rectangleTool.h"

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
	toolSettings.setFillColor(Colors::Theme.BackgroundDark);
	toolSelector.setFillColor(Colors::Theme.BackgroundLight);

	// Set their initial dynamic sizes
	ResizeUi();

	// Make all the buttons and tools
	CreateToolsAndButtons(size);

	// TODO: Don't do this emplace thing
	selectedToolText.emplace(*AssetManager::GetFont("arial"), currentTool->GetName(), 16u);
	selectedToolText->setFillColor(Colors::Theme.Foreground);
}

void Toolbar::CreateToolsAndButtons(float size)
{
	float padding = size / 10.0f;

	// Get the size and position of the buttons
	float buttonDimension = size - (padding * 2.0f);
	sf::Vector2f buttonSize = sf::Vector2f(buttonDimension, buttonDimension);
	sf::Vector2f position = sf::Vector2f(padding, size + padding);

	// TODO: Don't use scopes like this
	// Cursor tool
	{
		CursorTool* cursorTool = new CursorTool("Cursor", "hi");
		ImageButton* cursorButton = new ImageButton("./assets/cursor.png", buttonSize, position, sf::Keyboard::Key::V);
		cursorButton->SetCallback(SetTool(cursorTool));

		// Move the button down a bit
		position.y += padding + buttonDimension;

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

	// Rectangle tool
	{
		RectangleTool* rectangleTool = new RectangleTool("Rectangle", "Click and drag to resize");
		ImageButton* rectangleButton = new ImageButton("./assets/rectangle.png", buttonSize, position, sf::Keyboard::Key::R);
		rectangleButton->SetCallback(SetTool(rectangleTool));

		// Move the button down a bit
		position.y += padding + buttonDimension;

		// Make coppies of the two things and
		// place them in the lists
		uiElements.push_back(rectangleButton);
		tools.push_back(rectangleTool);
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

		selectedToolText->setString(currentTool->GetName());
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
	sf::Vector2u windowSize = Utils::GetWindow()->getSize();

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
	Utils::GetWindow()->draw(toolSelector);
	Utils::GetWindow()->draw(toolSettings);

	// Draw all the ui elements
	for (UiElement* uiElement : uiElements) uiElement->Draw();

	// Draw the selected tool
	currentTool->Draw();

	Utils::GetWindow()->draw(*selectedToolText);
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