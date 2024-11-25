#include <iostream>
#include "tile.h"
#include "map.h"

/**
 * @brief Main function, creates all objects and starts
 *        WorldRunner
 * 
 * @return Nothing 
 */
int main(int, char**) {
    char tmp;
    std::cout << "Hello, from Mentoring!\n";

    Map map(TileType::LAS);

    map.SetType(9, 0, TileType::OSADA_STARTOWA);

    map.PrintMap();


    std::cin >> tmp;
}
