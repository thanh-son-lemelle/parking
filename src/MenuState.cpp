#include "MenuState.hpp"
#include "Window.hpp"


MenuState::MenuState(Window &windowClass)
    : window(windowClass.getWindow())
{
}

void MenuState::draw()
{
    window.clear(sf::Color::Magenta);
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
    }
}