#include "MenuState.hpp"
#include "window.hpp"
#include "GameState.hpp"
#include <iostream> // For debug display
#include "resourceManager.hpp"

MenuState::MenuState(Window &windowClass)
    : window(windowClass.getWindow()),
      rectangle1(sf::Vector2f(200.0f, 100.0f)), // Initializing the first rectangle
      rectangle2(sf::Vector2f(200.0f, 100.0f)),  // Initializing the second rectangle
      windowClass(windowClass)

{
    sprite.setTexture(ResourceManager::getTexture("background"));
    spriteExitButton.setTexture(ResourceManager::getTexture("buttonExit"));
    spriteLevel1Button.setTexture(ResourceManager::getTexture("level1_button"));
    float scaleX = 800.0f / sprite.getTexture()->getSize().x;
    float scaleY = 600.0f / sprite.getTexture()->getSize().y;
    sprite.setScale(scaleX, scaleY);
    spriteExitButton.setPosition(300,360);
    spriteLevel1Button.setPosition(300,140);
}

void MenuState::draw()
{
    window.clear(sf::Color::Magenta);

    window.draw(this->sprite);

    // Size of the rectangles (twice as big)
    sf::Vector2f rectangleSize(200.0f, 100.0f);

    // Create two rectangles with the same size
    sf::RectangleShape rectangle1(rectangleSize);
    sf::RectangleShape rectangle2(rectangleSize);

    // Get the window size
    sf::Vector2u windowSize = window.getSize();

    // Calculate positions to center the rectangles
    sf::Vector2f position1((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f - 110.0f);
    sf::Vector2f position2((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f + 110.0f);

    // Position the rectangles
    rectangle1.setPosition(position1);
    rectangle2.setPosition(position2);

    // Set the color of the rectangles to blue
    rectangle1.setFillColor(sf::Color::Blue);
    rectangle2.setFillColor(sf::Color::Blue);

    // Draw the rectangles
    window.draw(rectangle1);
    window.draw(rectangle2);
    window.draw(this->spriteExitButton);
    window.draw(this->spriteLevel1Button);
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
            // Get the mouse coordinates relative to the window
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            // Convert mouse coordinates to float coordinates
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

            // Size of the rectangles
            sf::Vector2f rectangleSize(200.0f, 100.0f);

            // Get the window size
            sf::Vector2u windowSize = window.getSize();

            // Calculate rectangle positions
            sf::Vector2f position1((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f - 110.0f);
            sf::Vector2f position2((windowSize.x - rectangleSize.x) / 2.0f, (windowSize.y - rectangleSize.y) / 2.0f + 110.0f);

            // Check if click is inside rectangle 1 area
            if (mousePositionFloat.x >= position1.x && mousePositionFloat.x <= position1.x + rectangleSize.x &&
                mousePositionFloat.y >= position1.y && mousePositionFloat.y <= position1.y + rectangleSize.y)
            {
                GameState *gameState = new GameState(windowClass, "../../levels/level1.txt");
                windowClass.changeState(gameState);
            }
            // Check if click is inside rectangle 2 area
            else if (mousePositionFloat.x >= position2.x && mousePositionFloat.x <= position2.x + rectangleSize.x &&
                     mousePositionFloat.y >= position2.y && mousePositionFloat.y <= position2.y + rectangleSize.y)
            {
                window.close();
            }
        }
    }
}
