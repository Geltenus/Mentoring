#pragma once

#include "being.h"

class Adventurer : public Being
{
private:
    unsigned int strength;   // increases attack power and hp
    unsigned int agility;    // increases chances of critical attack and evasion
    unsigned int intellect;  // increases magical power and mp
    unsigned int tp;         // training points, 10 points at every level up
    unsigned int experience; // gathered experience points

public:
    unsigned int GetStrength()
    {
        return strength;
    }

    void SetStrength(unsigned int str)
    {
        strength = str;
    }

    unsigned int GetAgility()
    {
        return agility;
    }

    void SetAgility(unsigned int agi)
    {
        agility = agi;
    }

    unsigned int GetIntellect()
    {
        return intellect;
    }

    void SetIntellect(unsigned int intel)
    {
        intellect = intel;
    }

    Adventurer();
};