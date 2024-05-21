#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

// Grid class for drawing a grid
class Grid {
public:
    // Constructor for the Grid class
    Grid(int rows, int cols, int cellSize, int startX, int startY);

    // Method to draw the grid in the SFML window
    void draw(sf::RenderWindow& window);

private:
    int rows;       // Number of rows in the grid
    int cols;       // Number of columns in the grid
    int cellSize;   // Size of a grid cell
    int startX;     // Starting x position
    int startY;     // Starting y position
};

#endif // GRID_HPP
