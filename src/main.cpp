#include <iostream>
#include "adventurer.h"
#include "tile.h"
#include "map.h"

/**
 * @brief Main function, creates all objects and starts
 *        WorldRunner
 *
 * @return Nothing
 */
int main(int, char **)
{
    char tmp;
    std::cout << "Hello, from Mentoring!\n";

    Adventurer adventurer;

    Map map(TileType::LAS);

    map.SetType(9, 0, TileType::OSADA_STARTOWA);

    map.PrintMap();

    std::cout << adventurer.GetStrength();
    std::cout << "\033[43m           \033[0m";

    std::cin >> tmp;
}