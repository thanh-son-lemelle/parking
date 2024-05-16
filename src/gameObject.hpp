#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

// Classe abstraite GameObject représentant un élément affiché à l'écran
class GameObject {
public:
    // Constructeur de la classe GameObject
    GameObject(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height), prevX(x), prevY(y) {}

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
    void resolveCollision() {
        this->x = this->prevX;
        this->y = this->prevY;
    }

    // Méthode pour sauvegarder la position précédente
    void savePosition() {
        this->prevX = this->x;
        this->prevY = this->y;
    }
    virtual float getX() = 0;     // Getter pour la coordonnée x
    virtual float getY() = 0;    // Getter pour la coordonnée y
    virtual float getWidth() = 0;  // Getter pour width
    virtual float getHeight() = 0; // Getter pour height

protected:
    float x, y;       // Coordonnées de l'objet
    float width, height; // Taille de l'objet
    float prevX, prevY; // Coordonnées précédentes de l'objet
};

#endif // GAMEOBJECT_HPP