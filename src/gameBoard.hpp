#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <string>
#include <iostream>
#include "vehicle.hpp"

class GameBoard
{
private:
    

public:
    Vehicle *vehicleX;
    int vehicleXIndex;
    GameBoard();
    void addVehicle(char id, int x, int y, int length, Orientation orientation);
    bool moveVehicle(char id, int dx, int dy);
    bool isVictory() const;
    void printBoard() const;
    void loadFromFile(const std::string &filename);
    void draw(sf::RenderWindow &window);
    static std::vector<Vehicle> vehicles;
    void update(float deltaTime);
    bool checkWin();
};

#endif // GAMEBOARD_H
