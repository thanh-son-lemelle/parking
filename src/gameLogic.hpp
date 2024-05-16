#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "gameBoard.hpp"

class GameLogic {
private:
    GameBoard board;

public:
    GameLogic(const std::string levelFile);
    void draw(sf::RenderWindow &window);
};

#endif // GAMELOGIC_HPP