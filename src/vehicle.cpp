#include "vehicle.hpp"
#include "resourceManager.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

// Constructeur de la classe Vehicule
// Vehicle::Vehicle()
//     : GameObject(0, 0, 0, 0), isPlayer(false), shape(sf::Vector2f(0, 0)) {}

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
    shape.setPosition(x, y); // Met à jour la position de la forme
    sprite.setPosition(x, y);
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle destroyed" << std::endl;
}

// Méthode pour dessiner l'objet

void Vehicle::draw(sf::RenderWindow& window) {
    window.draw(this->shape); // Dessine la forme
    window.draw(this->sprite);
}

// Méthode pour gerer les entrées du clavier

void Vehicle::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        savePosition(); // Sauvegarde la position précédente
        if (event.key.code == sf::Keyboard::Up && orientation == VERTICAL) {
            std::cout << "Up key pressed" << std::endl;
            // Déplace le personnage vers le haut une seule fois
            y-= 100;
        } else if (event.key.code == sf::Keyboard::Down && orientation == VERTICAL) {
            // Déplace le personnage vers le bas une seule fois
            y+= 100;
        } else if (event.key.code == sf::Keyboard::Left && orientation == HORIZONTAL) {
            // Déplace le personnage vers la gauche une seule fois
            x-= 100;
        } else if (event.key.code == sf::Keyboard::Right && orientation == HORIZONTAL) {
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
    sprite.setPosition(x, y);
    shape.setPosition(x, y); // Met à jour la position de la forme
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