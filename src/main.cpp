#include <iostream>
#include <string>
#include "adventurer.h"
#include "tile.h"
#include "map.h"
#include "tui.h"
#include "render_plane.h"

/**
 * @brief Main function, creates all objects and starts
 *        WorldRunner
 *
 * @return Nothing
 */
int main(int, char **)
{
    char c_tmp;
    std::string s_tmp;
    Adventurer adventurer;
    Renderer renderer;
    TUI tui;
    RenderPlane plane;

    Map map(TileType::LAS);
    map.SetType(9, 0, TileType::OSADA_STARTOWA);

    Being enemy;
    enemy.SetName("Rat");
    enemy.SetLvl(7);
    enemy.SetCurrentHP(100);
    enemy.SetCurrentMP(25);
    enemy.SetMaxHP(150);
    enemy.SetMaxMP(77);

    std::cout << "\033[H" << "Press q to proceed further\n";

    getline(std::cin, s_tmp, 'q');

    RenderFightPlane fightPlane(renderer, tui, adventurer, enemy);
    RenderWalkPlane walkPlane(renderer, tui, adventurer);
    RenderInventoryPlane inventoryPlane(renderer, tui, adventurer);

    plane.Render(fightPlane);

    getline(std::cin, s_tmp, 'q');

    plane.Render(walkPlane);

    getline(std::cin, s_tmp, 'q');

    plane.Render(inventoryPlane);

    getline(std::cin, s_tmp, 'q');
}