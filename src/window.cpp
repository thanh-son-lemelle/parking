#include <SFML/Graphics.hpp>
#include <string>
#include "window.hpp"
#include "resourceManager.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

// Constructor of the Window class
Window::Window(const std::string& title, int width, int height)
    : window(sf::VideoMode(width, height), title) {
    ResourceManager::loadTextures();
    currentState = new MenuState(*this);
}

// Destructor of the Window class
Window::~Window() {
    delete currentState;
}

// Main method to run the window loop
void Window::run() {
    sf::Clock clock; // Create a clock to measure time
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds(); // Measure elapsed time

        currentState->handleInput();
        currentState->update(deltaTime);
        currentState->draw();
    }
}

void Window::changeState(State * newState){
    if (currentState != nullptr){
        delete currentState;
    }
    currentState = newState;
}
