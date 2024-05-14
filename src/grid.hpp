#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

// Classe Grid pour dessiner une grille
class Grid {
public:
    // Constructeur de la classe Grid
    Grid(int rows, int cols, int cellSize, int startX, int startY);

    // Méthode pour dessiner la grille dans la fenêtre SFML
    void draw(sf::RenderWindow& window);

private:
    int rows;       // Nombre de lignes de la grille
    int cols;       // Nombre de colonnes de la grille
    int cellSize;   // Taille d'une cellule de la grille
    int startX;     // Position de départ en x
    int startY;     // Position de départ en y
};

#endif // GRID_HPP