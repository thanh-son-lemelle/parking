#include <SFML/Graphics.hpp>

/*

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Grid Example");

    // Set up the grid dimensions
    const int rows = 6;
    const int cols = 6;
    const int cellSize = 100;

    // Create a 2D array to represent the grid
    sf::RectangleShape grid[rows][cols];

    // Initialize the grid cells
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j].setSize(sf::Vector2f(cellSize, cellSize));
            grid[i][j].setOutlineThickness(1);
            grid[i][j].setOutlineColor(sf::Color::Black);
            grid[i][j].setPosition(j * cellSize, i * cellSize);
            grid[i][j].setFillColor(sf::Color::White);
        }
    }

    // Highlight the specific cells
    // Yellow cell at C2 (row 2, col 1) and C3 (row 2, col 2)
    grid[2][1].setFillColor(sf::Color::Yellow);
    grid[2][2].setFillColor(sf::Color::Yellow);

    // Blue cells
    grid[0][3].setFillColor(sf::Color::Blue);
    grid[1][3].setFillColor(sf::Color::Blue);
    grid[1][5].setFillColor(sf::Color::Blue);
    grid[2][5].setFillColor(sf::Color::Blue);
    grid[2][3].setFillColor(sf::Color::Blue);
    grid[3][3].setFillColor(sf::Color::Blue);
    grid[3][4].setFillColor(sf::Color::Blue);
    grid[4][1].setFillColor(sf::Color::Blue);
    grid[4][2].setFillColor(sf::Color::Blue);
    grid[4][4].setFillColor(sf::Color::Blue);
    grid[4][5].setFillColor(sf::Color::Blue);
    grid[5][1].setFillColor(sf::Color::Blue);
    grid[5][0].setFillColor(sf::Color::Blue);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // Draw the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                window.draw(grid[i][j]);
            }
        }

        window.display();
    }

    return 0;
}

*/

#include "window.hpp"

int main() {
    // Création d'une instance de la classe Window avec un titre et des dimensions spécifiées
    Window window("Ma Fenêtre SFML", 800, 600);
    // Exécution de la boucle principale de la fenêtre
    window.run();

    return 0; // Fin du programme
}