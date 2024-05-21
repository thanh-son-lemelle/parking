#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

// Abstract class GameObject representing an element displayed on the screen
class GameObject {
public:
    // Constructor for the GameObject class
    GameObject(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height), prevX(x), prevY(y) {}

    // Virtual destructor to allow proper deletion of derived objects
    virtual ~GameObject() {}

    // Pure virtual methods
    virtual void draw(sf::RenderWindow& window) = 0; // Method to draw the object
    virtual void update(float deltaTime) = 0;       // Method to update the object

    // Method to check for collisions
    virtual bool intersects(const GameObject& other) const {
        return !(x + width <= other.x || other.x + other.width <= x || 
                 y + height <= other.y || other.y + other.height <= y);
    }

    // Method to resolve collisions
    void resolveCollision() {
        this->x = this->prevX;
        this->y = this->prevY;
    }

    // Method to save the previous position
    void savePosition() {
        this->prevX = this->x;
        this->prevY = this->y;
    }

    virtual float getX() = 0;     // Getter for the x coordinate
    virtual float getY() = 0;     // Getter for the y coordinate
    virtual float getWidth() = 0; // Getter for the width
    virtual float getHeight() = 0;// Getter for the height

protected:
    float x, y;             // Coordinates of the object
    float width, height;    // Size of the object
    float prevX, prevY;     // Previous coordinates of the object
};

#endif // GAMEOBJECT_HPP
