#include <SFML/Graphics.hpp>
#include <string>
#include "grid.hpp"
#include "window.hpp"
#include "resourceManager.hpp"

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
    : window(sf::VideoMode(width, height), title), selectedObject(nullptr) {
    // calcule pour centrer la grille
    int gridRows = 6;
    int gridCols = 6;
    int cellSize = 100;
    int startX = (width - gridCols * cellSize) / 2;
    int startY = (height - gridRows * cellSize) / 2;
    ResourceManager::loadTextures();

    grid = new Grid(gridRows, gridCols, cellSize, startX, startY);
    logic = new GameLogic(std::string("../../levels/level1.txt"));
}

// Destructeur de la classe Window
Window::~Window() {
    delete grid;
    delete logic;
}

// Méthode pour gérer les événements
void Window::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }else if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left){
                float mouseX =  static_cast<float>(event.mouseButton.x);
                float mouseY =  static_cast<float>(event.mouseButton.y);
                if (selectedObject){
                    selectedObject->setIsSelect();
                    selectedObject = nullptr;
                }
                for (auto &obj : GameBoard::vehicles)
                {
                    Vehicle *vehicle = &obj;
                    if (vehicle->contains(mouseX, mouseY))
                    {
                        selectedObject = vehicle;
                        selectedObject->setIsSelect();
                        break;
                    }
                }
            }
        }else if (selectedObject){
            selectedObject->handleInput(event);
        }
    }
}

// Méthode pour gérer les collisions
void Window::handleCollisions() {
    for (size_t i = 0; i < GameBoard::vehicles.size(); i++){
        for (size_t j = i + 1; j < GameBoard::vehicles.size(); j++){
            if (GameBoard::vehicles[i].intersects(GameBoard::vehicles[j])){
                //todo: gestion de la collision entre GameBoard::vehicles[i] et GameBoard::vehicles[j]
                //todo: empecher les objets de se superposer
                GameBoard::vehicles[i].resolveCollision();
                GameBoard::vehicles[j].resolveCollision();

                std:: cout << " position de gameobject : "<< std::endl;
                //todo: ajuste la position des objets pour éviter la collision
                std::cout << "Collision detected!" << std::endl;
            }
        }
    }
}

// Méthode principale pour exécuter la boucle de la fenêtre
void Window::run() {
    sf::Clock clock; // Création d'une horloge pour mesurer le temps
    while (window.isOpen()) {
        handleCollisions(); // Gestion des collisions
        processEvents(); // Gestion des événements

        float deltaTime = clock.restart().asSeconds(); // Mesure du temps écoulé

        logic->update(deltaTime);
        window.clear(sf::Color::Black);

        // Dessiner ici

        grid->draw(window);
        logic->draw(window);

        window.display();
    }
}