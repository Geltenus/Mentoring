#include <iostream>
#include <string>
#include "adventurer.h"
#include "tile.h"
#include "map.h"
#include "tui.h"

void GenerateFightPlane(Renderer r, TUI tui)
{
    tui.ClearTUI(r);

    tui.AddText(r, 0, 0, "LV 7");
    tui.AddText(r, 1, 0, "HP", ColorType::Bold_Red);
    tui.AddText(r, 2, 0, "MP", ColorType::Bold_Blue);
    tui.AddText(r, 3, 0, "EXP", ColorType::Bold_Magenta);
    tui.AddProgressBar(r, 1, 4, 30, 0.1, '/', ColorType::Bold_Red);
    tui.AddProgressBar(r, 2, 4, 30, 0.2, '/', ColorType::Bold_Blue);
    tui.AddProgressBar(r, 3, 4, 30, 0.3, '/', ColorType::Bold_Magenta);

    tui.AddReverseText(r, 0, 99, "Rat, LV 3");
    tui.AddText(r, 1, 97, "HP", ColorType::Bold_Red);
    tui.AddText(r, 2, 97, "MP", ColorType::Bold_Blue);
    tui.AddReverseProgressBar(r, 1, 99, 30, 1.0, '\\', ColorType::Bold_Red);
    tui.AddReverseProgressBar(r, 2, 99, 30, 0.8, '\\', ColorType::Bold_Blue);

    tui.AddText(r, 24, 0, "1. Attack.");
    tui.AddText(r, 26, 0, "2. Magic.");
    tui.AddText(r, 28, 0, "3. Inventory.");
    tui.AddText(r, 24, 49, "4. Escape");
    tui.AddText(r, 26, 49, "5. Catch.");

    tui.RenderTUI(r);
}

void GenerateWalkPlane(Renderer r, TUI tui)
{
    tui.ClearTUI(r);

    tui.AddText(r, 0, 0, "LV 7");
    tui.AddText(r, 1, 0, "HP", ColorType::Bold_Red);
    tui.AddText(r, 2, 0, "MP", ColorType::Bold_Blue);
    tui.AddText(r, 3, 0, "EXP", ColorType::Bold_Magenta);
    tui.AddProgressBar(r, 1, 4, 30, 0.4, '/', ColorType::Bold_Red);
    tui.AddProgressBar(r, 2, 4, 30, 0.5, '/', ColorType::Bold_Blue);
    tui.AddProgressBar(r, 3, 4, 30, 0.6, '/', ColorType::Bold_Magenta);

    tui.AddWrapedText(r, 15, ((99 - 40) / 2), 40, "You are inside a forest. All You can see are trees, lots of trees");

    tui.AddText(r, 24, 0, "1. Go NORTH.");
    tui.AddText(r, 26, 0, "2. Go EAST.");
    tui.AddText(r, 28, 0, "3. Go WEST.");
    tui.AddText(r, 24, 49, "4. Go SOUTH.");
    tui.AddText(r, 26, 49, "5. Rest.");
    tui.AddText(r, 28, 49, "6. Sleep.");

    tui.RenderTUI(r);
}

void GenerateInventoryPlane(Renderer r, TUI tui)
{
    tui.ClearTUI(r);

    tui.AddText(r, 0, 0, "LV 7");
    tui.AddText(r, 1, 0, "HP", ColorType::Bold_Red);
    tui.AddText(r, 2, 0, "MP", ColorType::Bold_Blue);
    tui.AddText(r, 3, 0, "EXP", ColorType::Bold_Magenta);
    tui.AddProgressBar(r, 1, 4, 30, 0.7, '/', ColorType::Bold_Red);
    tui.AddProgressBar(r, 2, 4, 30, 0.8, '/', ColorType::Bold_Blue);
    tui.AddProgressBar(r, 3, 4, 30, 0.9, '/', ColorType::Bold_Magenta);

    tui.AddText(r, 6, 0, "1. Sword.");
    tui.AddText(r, 8, 0, "2. Wand.");
    tui.AddText(r, 10, 0, "3. HP Potion.");
    tui.AddText(r, 12, 0, "4. Caged Rat.");
    tui.AddText(r, 14, 0, "5. Tent.");
    tui.AddText(r, 16, 0, "6. Torch.");

    tui.AddWrapedText(r, 1, 50, 49, "This Rat was catched by suprise. But be ware! It is furious about being in cage, proceed with caution");

    tui.RenderTUI(r);
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
    TUI tui;

    Map map(TileType::LAS);
    map.SetType(9, 0, TileType::OSADA_STARTOWA);

    std::cout << "\033[H" << "Press q to proceed further\n";

    getline(std::cin, s_tmp, 'q');

    GenerateFightPlane(renderer, tui);

    getline(std::cin, s_tmp, 'q');

    GenerateWalkPlane(renderer, tui);

    getline(std::cin, s_tmp, 'q');

    GenerateInventoryPlane(renderer, tui);

    getline(std::cin, s_tmp, 'q');
}