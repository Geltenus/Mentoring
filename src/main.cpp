#include <iostream>
#include <string>
#include "adventurer.h"
#include "tile.h"
#include "map.h"
#include "tui.h"
#include "plane_builder.h"
#include "world_runner.h"

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
    UserInput user_input;
    Fight fight;

    Map map(TileType::LAS);
    map.SetType(9, 0, TileType::OSADA_STARTOWA);

    Being enemy;
    enemy.SetName("Rat");
    enemy.SetLvl(7);
    enemy.SetCurrentHP(100);
    enemy.SetCurrentMP(25);
    enemy.SetMaxHP(150);
    enemy.SetMaxMP(77);

    WorldRunner wr(&fight, &user_input, tui, adventurer, enemy);

    std::cout << "\033[H" << "Press: \n"
              << "'q' to exit\n"
              << "'1' to render walk plane\n"
              << "'2' to render fight plane\n"
              << "'3' to render inventory plane\n";

    wr.Run();
}