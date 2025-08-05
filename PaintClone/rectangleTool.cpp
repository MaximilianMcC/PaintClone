#include "rectangleTool.h"

void RectangleTool::Select()
{
	// Switch the mouse cursor to be more representative of the shape
	Program::SetCursor(sf::Cursor::Type::Cross);
}

void RectangleTool::Deselect()
{
	Program::ResetCursor();
}

void RectangleTool::Update()
{
	
}