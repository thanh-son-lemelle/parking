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
    handleCollisions();
    board.update(deltaTime);
}

// Méthode pour gérer les collisions
void GameLogic::handleCollisions()
{
    for (size_t i = 0; i < GameBoard::vehicles.size(); i++)
    {
        for (size_t j = i + 1; j < GameBoard::vehicles.size(); j++)
        {
            if (GameBoard::vehicles[i].intersects(GameBoard::vehicles[j]))
            {
                // todo: gestion de la collision entre GameBoard::vehicles[i] et GameBoard::vehicles[j]
                // todo: empecher les objets de se superposer
                if (GameBoard::vehicles[i].getIsSelect() == true)
                {
                    GameBoard::vehicles[i].resolveCollision();
                } 
                else if (GameBoard::vehicles[j].getIsSelect() == true)
                {
                    GameBoard::vehicles[j].resolveCollision();
                }
                std::cout << " position de gameobject : " << std::endl;
                // todo: ajuste la position des objets pour éviter la collision
                std::cout << "Collision detected!" << std::endl;
            }
        }
    }
}