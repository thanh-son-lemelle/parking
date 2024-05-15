#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "grid.hpp"
#include "vehicule.hpp"

// Classe Window pour gérer la fenêtre SFML
class Window {
public:
    // Constructeur de la classe Window
    Window(const std::string& title, int width, int height);

    // Destructeur de la classe Window
    ~Window();

    // Méthode principale pour exécuter la boucle de la fenêtre
    void run();

private:
    sf::RenderWindow window; // Objet fenêtre de SFML
    Grid* grid;              // Pointeur vers un objet Grid
    std::vector<GameObject*> gameObjects ; // Vecteur de pointeurs vers des objets Vehicule

    // Méthode pour initialiser les objets

    void initGameObjects();
};

#endif // WINDOW_HPP