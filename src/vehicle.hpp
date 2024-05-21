#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include "gameObject.hpp"
enum Orientation
{
    HORIZONTAL,
    VERTICAL
};

class Vehicle : public GameObject { // Inherits from GameObject
public:
    // Constructor of the Vehicle class
    Vehicle(float x, float y, float width, float height, char id, Orientation orientation, bool isPlayer = false);
    ~Vehicle();
    // Method to draw the object
    void draw(sf::RenderWindow& window) override;

    // Method to update the object
    void update(float deltaTime) override;

    // Method to handle player inputs

    void handleInput(const sf::Event& event);

    void setIsSelect();

    // Method to check if mouse click is inside the object

    bool contains(float mouseX, float mouseY) const;

    char id;
    Orientation orientation;

    bool getIsSelect();

    float getX() override;
    float getY() override;
    float getWidth() override;
    float getHeight() override;

    void setTexture(const std::string &textureName, Orientation orientation);

private:
    bool isPlayer; // Boolean to know if the object is the player
    float speed; // Movement speed
    sf::RectangleShape shape; // Object shape
    bool isSelect;

    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // VEHICLE_HPP
