#include <iostream>
#include "map.h"

TileType Map::GetType(unsigned int x, unsigned int y)
{
    if ((x_max < x) || (y_max < y))
    {
        return TileType::NIC;
    }
    else
    {
        return tileMap[x][y];
    }
}

void Map::SetType(unsigned int x, unsigned int y, TileType type)
{
    if ((x_max < x) || (y_max < y))
    {
        return;
    }
    else
    {
        tileMap[x][y] = type;
    }
}

void Map::PrintMap()
{
    for (unsigned int i = 0; i < x_max; ++i)
    {
        for (unsigned int j = 0; j < y_max; ++j)
        {
            std::cout << static_cast<char>(tileMap[i][j]) << ' ';
        }
        std::cout << std::endl;
    }
}

Map::Map()
{
    for (unsigned int i = 0; i < x_max; ++i)
    {
        for (unsigned int j = 0; j < y_max; ++j)
        {
            tileMap[i][j] = TileType::NIC;
        }
    }
}

Map::Map(TileType type)
{
    for (unsigned int i = 0; i < x_max; ++i)
    {
        for (unsigned int j = 0; j < y_max; ++j)
        {
            tileMap[i][j] = type;
        }
    }
}