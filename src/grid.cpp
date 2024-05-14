#include "grid.hpp"

// Constructeur de la classe Grid
Grid::Grid(int rows, int cols, int cellSize, int startX, int startY)
    : rows(rows), cols(cols), cellSize(cellSize), startX(startX), startY(startY){
    // Initialisation de la grille avec les lignes et les colonnes spécifiées
}

// Méthode pour dessiner la grille dans la fenêtre SFML
void Grid::draw(sf::RenderWindow& window) {
    sf::RectangleShape line;
    line.setFillColor(sf::Color::White);

    // Dessiner les lignes horizontales
    for (int i = 0; i <= rows; ++i) {
        line.setSize(sf::Vector2f(cols * cellSize, 1));
        line.setPosition(startX, i * cellSize + startY);
        window.draw(line);
    }

    // Dessiner les lignes verticales
    for (int i = 0; i <= cols; ++i) {
        line.setSize(sf::Vector2f(1, rows * cellSize));
        line.setPosition(startX + i * cellSize, startY);
        window.draw(line);
    }
}