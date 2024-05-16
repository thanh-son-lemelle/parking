#include "GameBoard.hpp"
#include <fstream>
#include <sstream>
#include <windows.h>

std::vector<Vehicle> GameBoard::vehicles;
GameBoard::GameBoard() 
: vehicleX(nullptr) {}

void GameBoard::addVehicle(char id, int x, int y, int length, Orientation orientation)
{
    std::cout << "Adding vehicle " << id << " at (" << x << ", " << y << ") with length " << length << " and orientation " << (orientation == HORIZONTAL ? "HORIZONTAL" : "VERTICAL") << std::endl;
    Vehicle newVehicle;
    if (orientation == HORIZONTAL)
    {
        newVehicle = Vehicle(x *100, y*100, length*100, 100,id, orientation, id == 'X');
    }
    else {
        newVehicle = Vehicle(x*100, y*100, 100, length*100,id, orientation, id == 'X');
    }
    vehicles.push_back(newVehicle);
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