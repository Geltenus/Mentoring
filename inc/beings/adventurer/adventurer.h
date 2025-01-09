#pragma once

#include "being.h"

class Adventurer : public Being
{
private:
    unsigned int strength;   // increases attack power and hp
    unsigned int agility;    // increases chances of critical attack and evasion
    unsigned int intellect;  // increases magical power and mp
    unsigned int tp;         // training points
    unsigned int experience; // gathered experience points

    constexpr static unsigned int exp_per_lvl = 500;
    constexpr static unsigned int tp_per_lvl = 10;

public:
    unsigned int GetStrength();
    void SetStrength(unsigned int str);
    void AddStrength(unsigned int str);

    unsigned int GetAgility();
    void SetAgility(unsigned int agi);
    void AddAgility(unsigned int agi);

    unsigned int GetIntellect();
    void SetIntellect(unsigned int intel);
    void AddIntellect(unsigned int intel);

    unsigned int GetTP();
    void SetTP(unsigned int points);
    void AddTP(unsigned int points);

    unsigned int GetExperience();
    unsigned int GetExperienceToNextLvl();
    void SetExperience(unsigned int exp);
    void AddExperience(unsigned int exp);

    void LevelUp();

    Adventurer();
};