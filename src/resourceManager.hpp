#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

class ResourceManager
{
public:
    
    static void loadTextures();
    static sf::Texture &getTexture(const std::string &textureName);
    static void printTextures();

private:
    static std::map<std::string, sf::Texture> textures;
};

#endif // RESOURCE_MANAGER_H