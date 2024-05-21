#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "gameBoard.hpp"

class GameLogic {
private:
    GameBoard board;
    void handleCollisions(); //* Méthode pour gérer les collisions
    void verifyWin(); //* Méthode pour vérifier si le joueur a gagné
    bool isWin;

public:
    GameLogic(const std::string levelFile);
    ~GameLogic();
    void draw(sf::RenderWindow &window);
    void update(float deltaTime);
    bool getIsWin() const;
};

#endif // GAMELOGIC_HPP
