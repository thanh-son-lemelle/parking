#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "gameBoard.hpp"

class GameLogic {
private:
    GameBoard board;
    void handleCollisions(); //* Méthode pour gérer les collisions

public:
    GameLogic(const std::string levelFile);
    void draw(sf::RenderWindow &window);
    void update(float deltaTime);
};

#endif // GAMELOGIC_HPP