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
    GameState(Window& windowClass); //* Constructeur de la classe GameState
    ~GameState();              //* Destructeur de la classe GameState
    void handleInput() override;

    void update(float dt) override;

    void draw() override;
private:
    sf::RenderWindow& window; // Référence vers un objet Window
    Grid *grid;              // Pointeur vers un objet Grid
    Vehicle *selectedObject; // Pointeur vers l'objet Vehicule sélectionné

    // Méthode pour initialiser les objets
    GameLogic *logic;
    void processEvents();    //* Méthode pour gérer les événements
};

#endif // GAME_STATE_HPP