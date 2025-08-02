#include "assetManager.h"

std::map<std::string, sf::Texture> AssetManager::textures;
std::map<std::string, sf::Font> AssetManager::fonts;

void AssetManager::LoadTexture(std::string key, std::string path)
{
	// Load it
	sf::Texture texture;
	if (texture.loadFromFile(path) == false)
	{
		// If there was an issue then say
		// TODO: exit 1
		std::cerr << "Error loading texture at path '" << path << "' (looked in " << std::filesystem::current_path() << ")";
	}

	// The texture was loaded. Chuck it into
	// the dictionary so it may be used
	textures[key] = texture;
}

sf::Texture* AssetManager::GetTexture(std::string key)
{
	// TODO: Check for if they key exists or not
	return &textures[key];
}