#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include "gameObject.hpp"

/*
class Vehicule : public GameObject { // Hérite de GameObject

    public:
        Vehicule(float x, float y, float width, float height, bool isPlayer = false)
            : GameObject(x, y, width, height), isPlayer(isPlayer), shape(sf::Vector2f(width, height)) {
            shape.setPosition(x, y); // Définit la position de la forme
            if (isPlayer) {
                shape.setFillColor(sf::Color::Green); // Définit la couleur de la forme
            } else {
                shape.setFillColor(sf::Color::Red); // Définit la couleur de la forme
            }
        }

        // Méthode pour dessiner l'objet
        void draw(sf::RenderWindow& window) override {
            window.draw(shape); // Dessine la forme
        }

        // Méthode pour mettre à jour l'objet

        void update(float deltaTime) override {
            if (isPlayer) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    x -= 100 ; // Déplace le joueur vers la gauche
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    x += 100 ; // Déplace le joueur vers la droite
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    y -= 100 ; // Déplace le joueur vers le haut
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    y += 100 ; // Déplace le joueur vers le bas
                }
                //todo: ajouter la gestion des collisions
                //todo: ajouter la gestion des obstacles
            } else {
                
            }
            shape.setPosition(x, y); // Met à jour la position de la forme
            std::cout << "x: " << x << ", y: " << y << std::endl; // Affiche les coordonnées
            
        }

    private:
        bool isPlayer; // Booléen pour savoir si l'objet est le joueur
        sf::RectangleShape shape; // Forme de l'objet
};

#endif // VECHICULE_HPP
*/
enum Orientation
{
    HORIZONTAL,
    VERTICAL
};

class Vehicle : public GameObject { // Hérite de GameObject
public:
    // Constructeur de la classe Vehicule
    Vehicle(float x, float y, float width, float height, char id, Orientation orientation, bool isPlayer = false);
    Vehicle();
    // Méthode pour dessiner l'objet
    void draw(sf::RenderWindow& window) override;

    // Méthode pour mettre à jour l'objet
    void update(float deltaTime) override;

    // Méthode pour gerer les inputs du joueur
    void handleInput();

    char id;
    int lenght;
    Orientation orientation;

private:
    bool isPlayer; // Booléen pour savoir si l'objet est le joueur
    float speed = 100; // Vitesse de déplacement
    sf::RectangleShape shape; // Forme de l'objet
};

#endif // VECHICULE_HPP