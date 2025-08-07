#include "cursorTool.h"

void CursorTool::Select()
{
	Utils::SetCursor(sf::Cursor::Type::Arrow);
}

void CursorTool::Deselect()
{
	Utils::ResetCursor();
}