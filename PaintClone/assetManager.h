#pragma once
#include <map>
#include <string>
#include <iostream>
#include <filesystem>
#include "SFML/Graphics.hpp"

class AssetManager
{
private:
	static std::map<std::string, sf::Texture> textures;
	static std::map<std::string, sf::Font> fonts;

public:
	static void LoadTexture(std::string key, std::string path);
	static sf::Texture* GetTexture(std::string key);

	static void LoadFont(std::string key, std::string path);
	static sf::Font* GetFont(std::string key);
};