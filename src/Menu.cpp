#include "Menu.h"

#include <iostream>

void Menu::displayMainMenu()
{
    std::cout << "\n=========================\n";
    std::cout << " MAZE GENERATOR & SOLVER\n";
    std::cout << "=========================\n";
    std::cout << "1. Generate Maze\n";
    std::cout << "2. Solve DFS\n";
    std::cout << "3. Solve BFS\n";
    std::cout << "4. Exit\n";
}