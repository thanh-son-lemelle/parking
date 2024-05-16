#include "vehicle.hpp"
#include <SFML/Window/Keyboard.hpp>

// Constructeur de la classe Vehicule
Vehicle::Vehicle()
    : GameObject(0, 0, 0, 0), isPlayer(false), shape(sf::Vector2f(0, 0)) {}

Vehicle::Vehicle(float x, float y, float width, float height, char id, Orientation orientation, bool isPlayer)
    : GameObject(x * 100, y * 100, width * 100, height * 100), isPlayer(isPlayer), id(id), lenght(width), orientation(orientation), shape(sf::Vector2f(width * 100, height * 100))
{
    shape.setPosition(x, y); // Définit la position de la forme
    if (isPlayer) {
        shape.setFillColor(sf::Color::Green); // Définit la couleur de la forme
    } else {
        shape.setFillColor(sf::Color::Red); // Définit la couleur de la forme
    }
    shape.setPosition(x, y); // Met à jour la position de la forme
}

// Méthode pour dessiner l'objet

void Vehicle::draw(sf::RenderWindow& window) {
    window.draw(this->shape); // Dessine la forme
}

// Méthode pour gerer les entrées du clavier

void Vehicle::handleInput() {
    if (isPlayer) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                x -= speed; // Déplace le joueur vers la gauche
    
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                x += speed; // Déplace le joueur vers la droite
    
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                y -= speed; // Déplace le joueur vers le haut
    
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                y += speed; // Déplace le joueur vers le bas
    
        }
        x = std::max(100.0f, std::min(x, 700.0f - width)); // Limite les déplacements horizontaux
        y = std::max(0.0f, std::min(y, 600.0f - height)); // Limite les déplacements verticaux
        shape.setPosition(x, y); // Met à jour la position de la forme
        std::cout << "x: " << x << ", y: " << y << std::endl; // Affiche les coordonnées

    }
}

void Vehicle::update(float deltaTime) {
        handleInput(); // Gère les entrées du clavier
    }