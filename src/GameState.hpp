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
    GameState(Window& windowClass, std::string levelPath); //* Constructeur de la classe GameState
    ~GameState();              //* Destructeur de la classe GameState
    void handleInput() override;

    void update(float dt) override;

    void draw() override;
private:
    Window& windowClass;     // Référence vers un objet Window
    sf::RenderWindow& window; // Référence vers un objet Window
    Grid *grid;              // Pointeur vers un objet Grid
    Vehicle *selectedObject; // Pointeur vers l'objet Vehicule sélectionné

    // Méthode pour initialiser les objets
    GameLogic *logic;
    void processEvents();    //* Méthode pour gérer les événements
    void verifyWin();
    void resetVehicles();        //* Méthode pour vérifier si le joueur a gagné
};

#endif // GAME_STATE_HPP