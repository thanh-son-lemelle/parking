#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include "gameObject.hpp"

/*
class Vehicle : public GameObject { // Hérite de GameObject

    public:
        Vehicle(float x, float y, float width, float height, bool isPlayer = false)
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

    void handleInput(const sf::Event& event);

    void setIsSelect();

    // Méthode pour vérifier si le click de la souris est à l'intérieur de l'objet

    bool contains(float mouseX, float mouseY) const;

    char id;
    Orientation orientation;

private:
    bool isPlayer; // Booléen pour savoir si l'objet est le joueur
    float speed; // Vitesse de déplacement
    sf::RectangleShape shape; // Forme de l'objet
    bool isSelect;
};

#endif // VECHICULE_HPP