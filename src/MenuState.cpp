#include "MenuState.hpp"
#include "window.hpp"
#include "GameState.hpp"
#include <iostream> // Pour l'affichage de débogage
#include "resourceManager.hpp"



MenuState::MenuState(Window &windowClass)
    : window(windowClass.getWindow()),
      rectangle1(sf::Vector2f(200.0f, 100.0f)), // Initialisation du premier rectangle
      rectangle2(sf::Vector2f(200.0f, 100.0f))  // Initialisation du deuxième rectangle
      
{
    sprite.setTexture(ResourceManager::getTexture("background"));
    sprite.setScale(800,600);
    
}
void MenuState::draw()
{
    window.clear(sf::Color::Magenta);
    
    window.draw(this->sprite);

    // Taille des rectangles (deux fois plus grands)
    sf::Vector2f rectangleSize(200.0f, 100.0f);

    // Créer deux rectangles avec la même taille
    sf::RectangleShape rectangle1(rectangleSize);
    sf::RectangleShape rectangle2(rectangleSize);

    // Obtenir la taille de la fenêtre
    sf::Vector2u windowSize = window.getSize();

    // Calculer les positions pour centrer les rectangles
    sf::Vector2f position1((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f - 110.0f);
    sf::Vector2f position2((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f + 110.0f);

    // Positionner les rectangles
    rectangle1.setPosition(position1);
    rectangle2.setPosition(position2);

    // Définir la couleur des rectangles à bleu
    rectangle1.setFillColor(sf::Color::Blue);
    rectangle2.setFillColor(sf::Color::Blue);

    // Dessiner les rectangles
    window.draw(rectangle1);
    window.draw(rectangle2);

    window.display();
}

void MenuState::update(float dt)
{
}

void MenuState::handleInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            // Obtenir les coordonnées de la souris par rapport à la fenêtre
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            // Convertir les coordonnées de la souris en coordonnées de type float
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

            // Taille des rectangles
            sf::Vector2f rectangleSize(200.0f, 100.0f);

            // Obtenir la taille de la fenêtre
            sf::Vector2u windowSize = window.getSize();

            // Calculer les positions des rectangles
            sf::Vector2f position1((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f - 110.0f);
            sf::Vector2f position2((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f + 110.0f);

            // Vérifier si le clic est à l'intérieur de la zone du rectangle 1
            if (mousePositionFloat.x >= position1.x && mousePositionFloat.x <= position1.x + rectangleSize.x &&
                mousePositionFloat.y >= position1.y && mousePositionFloat.y <= position1.y + rectangleSize.y)
            {
                //WindowClass.chageState(GameState);
            }
            // Vérifier si le clic est à l'intérieur de la zone du rectangle 2
            else if (mousePositionFloat.x >= position2.x && mousePositionFloat.x <= position2.x + rectangleSize.x &&
                     mousePositionFloat.y >= position2.y && mousePositionFloat.y <= position2.y + rectangleSize.y)
            {
                window.close();
            }
        }
    }
}