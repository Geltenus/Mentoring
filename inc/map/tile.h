#pragma once

enum TileType
{
    OSADA_STARTOWA = 'S',
    OSADA = 'O',
    POLE = 'P',
    LAS = 'L',
    WODA = 'W',
    WODA_MOST = 'H',
    MIASTO = 'M',
    GORY = 'G',
    BAGNO = 'B',
    NIC = 'X',
};

class Tile
{
private:
    TileType tileType;

public:
    TileType GetType()
    {
        return tileType;
    }

    void SetType(TileType type)
    {
        tileType = type;
    }

    Tile()
    {
        tileType = TileType::NIC;
    }

    Tile(TileType typeInfo)
    {
        tileType = typeInfo;
    }
};