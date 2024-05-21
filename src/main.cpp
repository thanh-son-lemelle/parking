#include <SFML/Graphics.hpp>
#include "window.hpp"


int main() {
    // Create an instance of the Window class with a specified title and dimensions
    Window window("My SFML Window", 800, 600);
    // Run the main loop of the window
    window.run();

    return 0; // End of program
}