#include "adventurer.h"

Adventurer::Adventurer()
{
    this->SetLvl(1);
    this->SetMaxHP(100);
    this->SetMaxMP(50);
    strength = 10;
    agility = 10;
    intellect = 10;
    tp = 10;
    experience = 0;
};