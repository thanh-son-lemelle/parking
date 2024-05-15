#include "vehicule.hpp"
#include <SFML/Window/Keyboard.hpp>

// Constructeur de la classe Vehicule
Vehicule::Vehicule(float x, float y, float width, float height, bool isPlayer)
    : GameObject(x, y, width, height), isPlayer(isPlayer), shape(sf::Vector2f(width, height)) {
    shape.setPosition(x, y); // Définit la position de la forme
    if (isPlayer) {
        shape.setFillColor(sf::Color::Green); // Définit la couleur de la forme
    } else {
        shape.setFillColor(sf::Color::Red); // Définit la couleur de la forme
    }
    shape.setPosition(x, y); // Met à jour la position de la forme
}

// Méthode pour dessiner l'objet

void Vehicule::draw(sf::RenderWindow& window) {
    window.draw(shape); // Dessine la forme
}

// Méthode pour gerer les entrées du clavier

void Vehicule::handleInput() {
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

void Vehicule::update(float deltaTime) {
        handleInput(); // Gère les entrées du clavier
    }