#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "State.hpp"

// Window class to manage the SFML window
class Window {
public:
    // Constructor of the Window class
    Window(const std::string& title, int width, int height);

    // Destructor of the Window class
    ~Window();

    // Main method to run the window loop
    void run();
    void changeState(State * newState);

    // Method to get the dimensions of the window
    int getWidth() const { return window.getSize().x; }
    int getHeight() const { return window.getSize().y; }

    sf::RenderWindow &getWindow() { return window; }

private:
    sf::RenderWindow window; // SFML window object
      
    State* currentState; 
};

#endif // WINDOW_HPP
