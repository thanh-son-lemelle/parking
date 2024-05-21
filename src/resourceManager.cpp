#include "resourceManager.hpp"

std::map<std::string, sf::Texture> ResourceManager::textures;

void ResourceManager::loadTextures()
{
    if (!textures["player"].loadFromFile("../../assets/player.png"))
    {
        std::cerr << "Error loading player texture" << std::endl;
    }
    else {
        std::cout << "Textures loaded" << std::endl;
    }

    if (!textures["vehicle"].loadFromFile("../../assets/vehicle.png"))
    {
        std::cerr << "Error loading vehicle texture" << std::endl;
    }
    else {
        std::cout << "Textures loaded" << std::endl;
    }


    if (!textures["background"].loadFromFile("../../assets/bg_menu.jpg"))
    {
        std::cerr << "Error loading menu texture" << std::endl;
    }
    else {
        std::cout << "Textures loaded" << std::endl;
    }
    
}
sf::Texture &ResourceManager::getTexture(const std::string &textureName)
{
    return textures[textureName];
}

void ResourceManager::printTextures()
{
    for (const auto &pair : textures)
    {
        std::cout << "Texture: " << pair.first << std::endl;
    }
}