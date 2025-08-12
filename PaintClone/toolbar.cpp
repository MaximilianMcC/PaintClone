#include "toolbar.h"
#include "dialogueHandler.h"
#include "cursorTool.h"
#include "rectangleTool.h"
#include "circleTool.h"
#include "lineTool.h"

// TODO: Don't do this here idk. Put in utils
float LayoutInfo::Padding;
float LayoutInfo::BaseSize;
sf::Vector2f LayoutInfo::ButtonSize;



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
	LayoutInfo::BaseSize = screenSize.x / 30.0f;
	LayoutInfo::Padding = LayoutInfo::BaseSize / 10.0f;

	// Horizontal
	toolSettings = sf::RectangleShape(sf::Vector2(0.0f, LayoutInfo::BaseSize));

	// The vertical one is spawned beneath the settings one
	toolSelector = sf::RectangleShape(sf::Vector2(LayoutInfo::BaseSize, 0.0f));
	toolSelector.setPosition(sf::Vector2(0.0f, LayoutInfo::BaseSize));

	// Set the colors
	// TODO: Color themes
	toolSettings.setFillColor(Colors::Theme.BackgroundDark);
	toolSelector.setFillColor(Colors::Theme.BackgroundLight);

	// Make all the buttons and tools
	CreateToolsAndButtons();

	// Set initial dynamic sizes
	ResizeUi();

	// TODO: Don't do this emplace thing
	selectedToolText.emplace(*AssetManager::GetFont("arial"), currentTool->GetName(), 16u);
	selectedToolText->setFillColor(Colors::Theme.Foreground);
}

void Toolbar::CreateToolsAndButtons()
{
	// Just to make life easier
	float size = LayoutInfo::BaseSize;
	float padding = LayoutInfo::Padding;

	// Get the size and position of the buttons
	float buttonDimension = size - (padding * 2.0f);
	sf::Vector2f buttonSize = sf::Vector2f(buttonDimension, buttonDimension);
	sf::Vector2f position = sf::Vector2f(padding, size + padding);

	// Store the button size for other classes
	LayoutInfo::ButtonSize = buttonSize;

	// TODO: Don't use scopes like this
	// Cursor tool
	{
		CursorTool* tool = new CursorTool("Cursor", "hi");
		ImageButton* button = new ImageButton("./assets/cursor.png", buttonSize, position, sf::Keyboard::Key::V);
		button->SetCallback(SetTool(tool));

		// Move the button down a bit
		position.y += padding + buttonDimension;

		// Make coppies of the two things and
		// place them in the lists
		uiElements.push_back(button);
		tools.push_back(tool);

		// By default the cursor tool is the current one
		//? only kinda acceptable to use [0] here idk
		// TODO: Don't hardcode index and do this
		//! fix rn (bad)
		currentTool = tools[0];
	}

	// Rectangle tool
	{
		RectangleTool* tool = new RectangleTool("Rectangle", "Click and drag to resize. Hold shift to lock aspect ratio");
		ImageButton* button = new ImageButton("./assets/rectangle.png", buttonSize, position, sf::Keyboard::Key::R);
		button->SetCallback(SetTool(tool));

		// Move the button down a bit
		position.y += padding + buttonDimension;

		// Make coppies of the two things and
		// place them in the lists
		uiElements.push_back(button);
		tools.push_back(tool);
	}

	// Circle tool
	{
		CircleTool* tool = new CircleTool("Circle", "Click and drag to resize. Hold shift to lock aspect ratio");
		ImageButton* button = new ImageButton("./assets/circle.png", buttonSize, position, sf::Keyboard::Key::C);
		button->SetCallback(SetTool(tool));

		// Move the button down a bit
		position.y += padding + buttonDimension;

		// Make coppies of the two things and
		// place them in the lists
		uiElements.push_back(button);
		tools.push_back(tool);
	}

	// Line tool
	{
		LineTool* tool = new LineTool("Line", "Click and drag to resize");
		ImageButton* button = new ImageButton("./assets/line.png", buttonSize, position, sf::Keyboard::Key::S);
		button->SetCallback(SetTool(tool));

		// Move the button down a bit
		position.y += padding + buttonDimension;

		// Make coppies of the two things and
		// place them in the lists
		uiElements.push_back(button);
		tools.push_back(tool);
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