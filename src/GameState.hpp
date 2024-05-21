#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"
#include "grid.hpp"
#include "vehicle.hpp"
#include "gameLogic.hpp"
#include <SFML/Graphics.hpp>

class Window;

class GameState : public State
{
public:
    GameState(Window& windowClass, std::string levelPath); //* Constructor for the GameState class
    ~GameState();                   //* Destructor for the GameState class
    void handleInput() override;

    void update(float dt) override;

    void draw() override;
    
private:
    Window &windowClass;
    sf::RenderWindow& window; // Reference to a Window object
    Grid *grid;               // Pointer to a Grid object
    Vehicle *selectedObject;  // Pointer to the selected Vehicle object

    GameLogic *logic;         // Pointer to a GameLogic object
    void processEvents();     // Method to handle events

    void verifyWin();
    void resetVehicles();
};

#endif // GAME_STATE_HPP
