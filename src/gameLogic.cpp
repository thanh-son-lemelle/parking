#include "GameLogic.hpp"
#include <iostream>

GameLogic::GameLogic(const std::string levelFile)
{
    board.loadFromFile(levelFile);
}
void GameLogic::draw(sf::RenderWindow &window)
{
    board.draw(window);
}

void GameLogic::update(float deltaTime)
{
    board.update(deltaTime);
}