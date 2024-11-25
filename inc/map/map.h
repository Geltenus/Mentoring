#pragma once

#include "tile.h"

class Map
{
private:
    constexpr static unsigned int x_max = 10;
    constexpr static unsigned int y_max = 10;
    TileType tileMap[x_max][y_max];

public:
    TileType GetType(unsigned int x, unsigned int y);
    void SetType(unsigned int x, unsigned int y, TileType type);
    void PrintMap();
    Map();
    Map(TileType type);
};