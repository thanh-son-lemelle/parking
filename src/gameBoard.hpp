#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <string>
#include <iostream>
#include "vehicle.hpp"

class GameBoard
{
private:
    bool isWin;
    bool checkWin();
    Vehicle *vehicleX;
    int vehicleXIndex;

public:
    GameBoard();
    ~GameBoard();
    void addVehicle(char id, int x, int y, int length, Orientation orientation);
    void printBoard() const;
    void loadFromFile(const std::string &filename);
    void draw(sf::RenderWindow &window);
    static std::vector<Vehicle> vehicles;
    void update(float deltaTime);
    bool getIsWin() const;

};

#endif // GAMEBOARD_H
