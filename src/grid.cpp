#include "grid.hpp"

// Constructor for the Grid class
Grid::Grid(int rows, int cols, int cellSize, int startX, int startY)
    : rows(rows), cols(cols), cellSize(cellSize), startX(startX), startY(startY) {
    // Initialize the grid with the specified rows and columns
}

// Method to draw the grid in the SFML window
void Grid::draw(sf::RenderWindow& window) {
    sf::RectangleShape line;
    line.setFillColor(sf::Color::White);

    // Draw horizontal lines
    for (int i = 0; i <= rows; ++i) {
        line.setSize(sf::Vector2f(cols * cellSize, 1));
        line.setPosition(startX, i * cellSize + startY);
        window.draw(line);
    }

    // Draw vertical lines
    for (int i = 0; i <= cols; ++i) {
        line.setSize(sf::Vector2f(1, rows * cellSize));
        line.setPosition(startX + i * cellSize, startY);
        window.draw(line);
    }
}
