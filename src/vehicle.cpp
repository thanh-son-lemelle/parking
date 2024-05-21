#include "vehicle.hpp"
#include "resourceManager.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

// Constructor of the Vehicle class
Vehicle::Vehicle(float x, float y, float width, float height, char id, Orientation orientation, bool isPlayer)
    : GameObject(x, y , width, height), isPlayer(isPlayer), id(id), orientation(orientation), shape(sf::Vector2f(width, height))
{
    isSelect = false;  
    shape.setFillColor(sf::Color(0, 0, 0, 128));
    if (isPlayer) {
        setTexture(std::string("player"), orientation);
    } else {
        if (orientation == HORIZONTAL && width == 200 || orientation == VERTICAL && height == 200)
        {
            setTexture(std::string("vehicle"), orientation);
        }
        else if (orientation == HORIZONTAL && width == 300 || orientation == VERTICAL && height == 300)
        {
            setTexture(std::string("bus"), orientation);
        }
    }
    shape.setPosition(x, y); // Update the shape's position
    sprite.setPosition(x, y);
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle destroyed" << std::endl;
}

// Method to draw the object

void Vehicle::draw(sf::RenderWindow& window) {
    window.draw(this->shape); // Draw the shape
    window.draw(this->sprite);
}

// Method to handle keyboard input

void Vehicle::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        savePosition(); // Save the previous position
        if (event.key.code == sf::Keyboard::Up && orientation == VERTICAL) {
            std::cout << "Up key pressed" << std::endl;
            // Move the character up once
            y -= 100;
        } else if (event.key.code == sf::Keyboard::Down && orientation == VERTICAL) {
            // Move the character down once
            y += 100;
        } else if (event.key.code == sf::Keyboard::Left && orientation == HORIZONTAL) {
            // Move the character left once
            x -= 100;
        } else if (event.key.code == sf::Keyboard::Right && orientation == HORIZONTAL) {
            // Move the character right once
            x += 100;
        }
        
        x = std::max(100.0f, std::min(x, 700.0f - width)); // Limit horizontal movements
        y = std::max(0.0f, std::min(y, 600.0f - height)); // Limit vertical movements
        std::cout << "x: " << x << ", y: " << y << ", prevX : "<< prevX << ", prevY : " << prevY << std::endl; // Display coordinates
    }
}

// Method to check if the click is within the object's area

bool Vehicle::contains(float mouseX, float mouseY) const {
    return shape.getGlobalBounds().contains(mouseX, mouseY);
}

void Vehicle::update(float deltaTime) {
    sprite.setPosition(x, y);
    shape.setPosition(x, y); // Update the shape's position
    if (isSelect)
    {
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::Yellow);
    }
    else
    {
        shape.setOutlineThickness(0);
    }
}

void Vehicle::setIsSelect() { //! Set the object as selected 
    isSelect = !isSelect;
}

float Vehicle::getX() {
    return this->x;
}

float Vehicle::getY() {
    return this->y;
}

float Vehicle::getWidth() {
    return this->width;
}

float Vehicle::getHeight() {
    return this->height;
}

bool Vehicle::getIsSelect() {
    return this->isSelect;
}

void Vehicle::setTexture(const std::string &textureName, Orientation orientation)
{
    sprite.setTexture(ResourceManager::getTexture(textureName));
    float scaleX, scaleY;
    if (orientation == HORIZONTAL)
    {
        sprite.setOrigin(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2);
        sprite.setRotation(90);
        sprite.setOrigin(0, 92);
        scaleX = this->height / sprite.getTexture()->getSize().x;
        scaleY = this->width / sprite.getTexture()->getSize().y;
    }
    else
    {
        scaleX = this->width / sprite.getTexture()->getSize().x;
        scaleY = this->height / sprite.getTexture()->getSize().y;
    }
    sprite.setScale(scaleX, scaleY);
}
