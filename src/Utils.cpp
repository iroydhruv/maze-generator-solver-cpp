#include "Utils.h"

#include <iostream>

namespace Utils
{
    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void pauseScreen()
    {
        std::cout << "\nPress Enter...";
        std::cin.get();
    }

    std::string mazeToString()
    {
        return "";
    }
}