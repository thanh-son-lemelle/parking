#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "State.hpp"

// Classe Window pour gérer la fenêtre SFML
class Window {
public:
    // Constructeur de la classe Window
    Window(const std::string& title, int width, int height);

    // Destructeur de la classe Window
    ~Window();

    // Méthode principale pour exécuter la boucle de la fenêtre
    void run();
    void chageState(State * newState);

    // Méthode pour obtenir les dimensions de la fenêtre
    int getWidth() const { return window.getSize().x; }
    int getHeight() const { return window.getSize().y; }

    sf::RenderWindow &getWindow() { return window; }

private:
    sf::RenderWindow window; // Objet fenêtre de SFML
      
    State* currentState; 
};

#endif // WINDOW_HPP