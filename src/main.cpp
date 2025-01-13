#include <iostream>
#include <string>
#include "adventurer.h"
#include "tile.h"
#include "map.h"
#include "tui.h"
#include "plane_builder.h"

/**
 * @brief Supporting function. Prepares TUI for new PLANE,
 *        builds PLANE and finally renders it.
 *
 * @return Nothing
 */
static void RenderPlane(TUI &tui, IPlaneBuilder &plane)
{
    PlaneBuilder builder;

    tui.ClearTUI();

    builder.Build(plane);

    tui.RenderTUI();
}

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
    TUI tui(renderer);

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

    FightPlaneBuilder fightPlane(tui, adventurer, enemy);
    WalkPlaneBuilder walkPlane(tui, adventurer);
    InventoryPlaneBuilder inventoryPlane(tui, adventurer);

    RenderPlane(tui, fightPlane);

    getline(std::cin, s_tmp, 'q');

    RenderPlane(tui, walkPlane);

    getline(std::cin, s_tmp, 'q');

    RenderPlane(tui, inventoryPlane);

    getline(std::cin, s_tmp, 'q');
}