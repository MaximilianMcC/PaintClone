#pragma once

#include "program.h"
#include "colors.h"

float* Program::deltaTime = nullptr;
sf::RenderWindow* Program::window = nullptr;

sf::Cursor::Type Program::currentCursor = sf::Cursor::Type::Arrow;
sf::Cursor::Type Program::previousCursor = sf::Cursor::Type::Arrow;

// This shouldn't really be in here but like
// I wasn't bothered to make a whole file just
// for this single line so its going in here
// since this file is already filled with a heap
// of rinky as cpp specific things (C# better)
ColorTheme Colors::Theme = Colors::Light;
