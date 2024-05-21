#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"

class Window;

class MenuState : public State
{
public:
    MenuState(Window& windowClass); //* Constructeur de la classe MenuState
    void handleInput() override;
    void update(float dt) override;
    void draw() override;

private:
    sf::RenderWindow &window;
    sf::RectangleShape rectangle1;
    sf::RectangleShape rectangle2;
    sf::Sprite sprite;
};

#endif // MENU_STATE_HPP
