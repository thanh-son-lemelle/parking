#include <SFML/Graphics.hpp>
#include <string>
#include "grid.hpp"
#include "window.hpp"

//! Classe Window avec pointeur
/*
class Window {
public:
    Window(const std::string& title, int width, int height) {
        // Création de la fenêtre
        window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    }

    ~Window() {
        delete window;
    }

    void run() {
        // Boucle principale de la fenêtre
        while (window->isOpen()) {
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            window->clear(sf::Color::Black); // Nettoyage de l'écran

            // Dessiner ici
            //todo utiliser la classe Grid

            window->display(); // Affichage de l'écran
        }
    }

private:
    sf::RenderWindow* window;
};
*/
//! Classe Window sans pointeur
/*utilisation des sf::RenderWindow sans pointeur
 pour éviter la gestion manuelle de la mémoire 
 et profiter de la RAII (Resource Acquisition Is Initialization) 
 en C++.

Voici un exemple utilisant sf::RenderWindow sans pointeur :
*/
/*
class Window {
public:
    Window(const std::string& title, int width, int height)
        : window(sf::VideoMode(width, height), title) {
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);

            // Dessiner ici
            //todo utiliser la classe Grid
            Grid grid(6, 6, 100);

            window.display();
        }
    }

private:
    sf::RenderWindow window;
};

*/

// Constructeur de la classe Window
Window::Window(const std::string& title, int width, int height)
    : window(sf::VideoMode(width, height), title) {
    // calculer pour centrer la grille
    int gridRows = 6;
    int gridCols = 6;
    int cellSize = 100;
    int startX = (width - gridCols * cellSize) / 2;
    int startY = (height - gridRows * cellSize) / 2;

    grid = new Grid(gridRows, gridCols, cellSize, startX, startY);
    board = new GameLogic(std::string("../../levels/level1.txt"));
}

// Destructeur de la classe Window
Window::~Window() {
    delete grid;
    for (auto obj : gameObjects) {
        delete obj;
    }
}
// Méthode pour initialiser les objets
void Window::initGameObjects() {
    // Créer un joueur
    // Orientation orientation = HORIZONTAL;
    // Vehicle* player = new Vehicle(1, 5, 2, 1,'X', orientation , true);
    // gameObjects.push_back(player);

    // Créer des ennemis
    // for (int i = 0; i < 6; i++) {
    //     Vehicle* enemy = new Vehicle(i, 5, 1, 1,'B', orientation, false);
    //     gameObjects.push_back(enemy);
    // }
}
// Méthode principale pour exécuter la boucle de la fenêtre
void Window::run() {
    sf::Clock clock; // Création d'une horloge pour mesurer le temps

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds(); // Mesure du temps écoulé

        // Mise à jour des objets
        for (auto obj : gameObjects) {
            obj->update(deltaTime); // Mise à jour de chaque objet
        }

        window.clear(sf::Color::Black);

        // Dessiner ici

        grid->draw(window);
        board->draw(window);

        window.display();
    }
}