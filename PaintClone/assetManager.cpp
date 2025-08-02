#include "assetManager.h"

std::map<std::string, sf::Texture> AssetManager::textures;
std::map<std::string, sf::Image> AssetManager::images;
std::map<std::string, sf::Font> AssetManager::fonts;

// TODO: Like all this is copy pasted (don't)
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

// TODO: Like all this is copy pasted (don't)
sf::Texture* AssetManager::GetTexture(std::string key)
{
	// TODO: Check for if they key exists or not
	return &textures[key];
}

// TODO: Like all this is copy pasted (don't)
void AssetManager::LoadImage(std::string key, std::string path)
{
	// Load it
	sf::Image image;
	if (image.loadFromFile(path) == false)
	{
		// If there was an issue then say
		// TODO: exit 1
		std::cerr << "Error loading image at path '" << path << "' (looked in " << std::filesystem::current_path() << ")";
	}

	// The image was loaded. Chuck it into
	// the dictionary so it may be used
	images[key] = image;
}

sf::Image* AssetManager::LoadAndGetImage(std::string key, std::string path)
{
	LoadImage(key, path);
	return GetImage(key);
}

// TODO: Like all this is copy pasted (don't)
sf::Image* AssetManager::GetImage(std::string key)
{
	// TODO: Check for if they key exists or not
	return &images[key];
}