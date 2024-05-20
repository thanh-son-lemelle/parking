#include "GameState.hpp"
#include "Window.hpp"

GameState::GameState(Window &windowClass)
    : window(windowClass.getWindow()), selectedObject(nullptr)
{
    // calcule pour centrer la grille
    int gridRows = 6;
    int gridCols = 6;
    int cellSize = 100;
    int startX = (windowClass.getWidth() - gridCols * cellSize) / 2;
    int startY = (windowClass.getHeight() - gridRows * cellSize) / 2;

    grid = new Grid(gridRows, gridCols, cellSize, startX, startY);
    logic = new GameLogic(std::string("../../levels/level1.txt"));
}

// Destructeur de la classe Window
GameState::~GameState()
{
    delete grid;
    delete logic;
}

void GameState::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                float mouseX = static_cast<float>(event.mouseButton.x);
                float mouseY = static_cast<float>(event.mouseButton.y);
                if (selectedObject)
                {
                    selectedObject->setIsSelect();
                    selectedObject = nullptr;
                }
                for (auto &obj : GameBoard::vehicles)
                {
                    Vehicle *vehicle = &obj;
                    if (vehicle->contains(mouseX, mouseY))
                    {
                        selectedObject = vehicle;
                        selectedObject->setIsSelect();
                        break;
                    }
                }
            }
        }
        else if (selectedObject)
        {
            selectedObject->handleInput(event);
        }
    }
}

// Méthode pour gérer les collisions
void GameState::handleCollisions()
{
    for (size_t i = 0; i < GameBoard::vehicles.size(); i++)
    {
        for (size_t j = i + 1; j < GameBoard::vehicles.size(); j++)
        {
            if (GameBoard::vehicles[i].intersects(GameBoard::vehicles[j]))
            {
                // todo: gestion de la collision entre GameBoard::vehicles[i] et GameBoard::vehicles[j]
                // todo: empecher les objets de se superposer
                GameBoard::vehicles[i].resolveCollision();
                GameBoard::vehicles[j].resolveCollision();

                std::cout << " position de gameobject : " << std::endl;
                // todo: ajuste la position des objets pour éviter la collision
                std::cout << "Collision detected!" << std::endl;
            }
        }
    }
}

void GameState::handleInput()
{
    processEvents();
}

void GameState::update(float dt)
{
    handleCollisions();
    logic->update(dt);
}

void GameState::draw()
{
    window.clear(sf::Color::Black);
    grid->draw(window);
    logic->draw(window);
    window.display();
}