#pragma once
#include "SFML/Graphics.hpp"

// TODO: Different icons and fonts for different themes
struct ColorTheme
{
	sf::Color BackgroundDark;
	sf::Color BackgroundLight;
	sf::Color Foreground;
};

struct Colors {
	static ColorTheme Theme;

	inline static const ColorTheme Light = {
		sf::Color(0xf0f0f0FF),
		sf::Color(0xdcdcdcFF),
		sf::Color::Black
	};

	inline static const ColorTheme Dark = {
		sf::Color(0x333333FF),
		sf::Color(0x222222FF),
		sf::Color::White
	};

	// TODO: Crazy shortcut to activate theme
	inline static const ColorTheme HotdogStand = {
		sf::Color(0xff0000FF),
		sf::Color(0xffff00FF),
		sf::Color::Black
	};
};