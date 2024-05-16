#include "GameBoard.hpp"
#include <fstream>
#include <sstream>
#include <windows.h>

GameBoard::GameBoard() 
: board(6, std::vector<char>(6, '0')), vehicleX(nullptr) {}

void GameBoard::addVehicle(char id, int x, int y, int length, Orientation orientation)
{
    Vehicle newVehicle;
    if (orientation == HORIZONTAL)
    {
        newVehicle = Vehicle(x, y, length, 1,id, orientation, id == 'X');
    }
    else {
        newVehicle = Vehicle(x, y, 1, length,id, orientation, id == 'X');
    }
    vehicles.push_back(newVehicle);
    for (int i = 0; i < length; ++i)
    {
        if (orientation == HORIZONTAL)
        {
            board[y][x + i] = id;
        }
        else
        {
            board[y + i][x] = id;
        }
    }
    if (id == 'X')
    {
        vehicleX = &vehicles.back();
    }
}

void GameBoard::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        char id;
        int x, y, lenght;
        char orientationChar;
        iss >> id >> x >> y >> lenght >> orientationChar;

        Orientation orientation = (orientationChar == 'H') ? HORIZONTAL : VERTICAL;
        addVehicle(id, x, y, lenght, orientation);
    }
    file.close();
    for (Vehicle &vehicle : vehicles)
    {
        std::cout << vehicle.id << std::endl;
    }
}

void GameBoard::draw(sf::RenderWindow &window)
{
    
    for (Vehicle &vehicle : vehicles)
    {
        vehicle.draw(window);
    }
}