#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"

class Window;

class MenuState : public State
{
public:
    MenuState(Window& windowClass); //* Constructor for the MenuState class
    void handleInput() override;
    void update(float dt) override;
    void draw() override;

private:
    sf::RenderWindow &window;
    sf::RectangleShape rectangle1;
    sf::RectangleShape rectangle2;
    sf::Sprite sprite;
    sf::Sprite spriteExitButton;
    sf::Sprite spriteLevel1Button;
};

#endif // MENU_STATE_HPP
