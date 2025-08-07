#include "rectangleTool.h"

void RectangleTool::Select()
{
	// Switch the mouse cursor to be more representative of the shape
	Utils::SetCursor(sf::Cursor::Type::Cross);
}

void RectangleTool::Deselect()
{
	Utils::ResetCursor();
}

void RectangleTool::Update()
{
	
}