#pragma once

#include "utils.h"
#include "colors.h"

float* Utils::deltaTime = nullptr;
sf::RenderWindow* Utils::window = nullptr;

sf::Cursor::Type Utils::currentCursor = sf::Cursor::Type::Arrow;
sf::Cursor::Type Utils::previousCursor = sf::Cursor::Type::Arrow;
bool Utils::usingTemporaryCursor = false;
sf::Cursor::Type Utils::temporaryCursor;

ColorTheme Colors::Theme = Colors::Light;
