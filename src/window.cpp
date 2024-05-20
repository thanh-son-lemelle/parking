#include <SFML/Graphics.hpp>
#include <string>
#include "window.hpp"
#include "resourceManager.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

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
    ResourceManager::loadTextures();
    currentState = new MenuState(*this);
}

// Destructeur de la classe Window
Window::~Window() {
    delete currentState;
}

// Méthode principale pour exécuter la boucle de la fenêtre
void Window::run() {
    sf::Clock clock; // Création d'une horloge pour mesurer le temps
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds(); // Mesure du temps écoulé

        currentState->handleInput();
        currentState->update(clock.restart().asSeconds());
        currentState->draw();
    }
}

void Window::chageState(State * newState){
    if (currentState != nullptr){
        delete currentState;
    }
    currentState = newState;
}