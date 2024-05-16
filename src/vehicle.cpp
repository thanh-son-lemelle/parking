#include "vehicle.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

// Constructeur de la classe Vehicle
Vehicle::Vehicle(float x, float y, float width, float height, bool isPlayer)
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

void Vehicle::draw(sf::RenderWindow& window) {
    window.draw(shape); // Dessine la forme
}

// Méthode pour gerer les entrées du clavier

void Vehicle::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        savePosition(); // Sauvegarde la position précédente
        if (event.key.code == sf::Keyboard::Up) {
            std::cout << "Up key pressed" << std::endl;
            // Déplace le personnage vers le haut une seule fois
            y-= 100;
        } else if (event.key.code == sf::Keyboard::Down) {
            // Déplace le personnage vers le bas une seule fois
            y+= 100;
        } else if (event.key.code == sf::Keyboard::Left) {
            // Déplace le personnage vers la gauche une seule fois
            x-= 100;
        } else if (event.key.code == sf::Keyboard::Right) {
            // Déplace le personnage vers la droite une seule fois
            x+= 100;
        }
        
        x = std::max(100.0f, std::min(x, 700.0f - width)); // Limite les déplacements horizontaux
        y = std::max(0.0f, std::min(y, 600.0f - height)); // Limite les déplacements verticaux
        std::cout << "x: " << x << ", y: " << y << ", prevX : "<< prevX << ", prevY : " << prevY << std::endl; // Affiche les coordonnées
        
    }
}

// Méthode pour verifier si le clic est dans la zone de l'objet

bool Vehicle::contains(float mouseX, float mouseY) const {
    return shape.getGlobalBounds().contains(mouseX, mouseY);
}


void Vehicle::update(float deltaTime) {
    shape.setPosition(x, y); // Met à jour la position de la forme
}
