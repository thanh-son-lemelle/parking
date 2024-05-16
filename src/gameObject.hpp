#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

// Classe abstraite GameObject représentant un élément affiché à l'écran
class GameObject {
public:
    // Constructeur de la classe GameObject
    GameObject(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

    // Destructeur virtuel pour permettre la suppression correcte des objets dérivés
    virtual ~GameObject() {}

    // Méthodes virtuelles pures
    virtual void draw(sf::RenderWindow& window) = 0; // Méthode pour dessiner l'objet
    virtual void update(float deltaTime) = 0;       // Méthode pour mettre à jour l'objet


    // Méthode pour verifier les collisions

    virtual bool intersects (const GameObject& other) const {
        return !(x + width <= other.x || other.x + other.width <= x || 
                 y + height <= other.y || other.y + other.height <= y);
    }


    // Méthode pour résoudre les collisions
    void resolveCollision(GameObject& other) {
        float overlapLeft = (x+width) - other.x;
        float overlapRight = (other.x + other.width) - x;
        float overlapTop = (y + height) - other.y;
        float overlapBottom = (other.y + other.height) - y;

        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            x -= overlapLeft;
        } else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            x += overlapRight;
        } else if (overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight) {
            y -= overlapTop;
        } else {
            y += overlapBottom;
        }
    }
protected:
    float x, y;       // Coordonnées de l'objet
    float width, height; // Taille de l'objet
};

#endif // GAMEOBJECT_HPP