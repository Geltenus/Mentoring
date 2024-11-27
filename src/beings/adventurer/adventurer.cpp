#include "adventurer.h"

unsigned int Adventurer::GetStrength()
{
    return strength;
}

void Adventurer::SetStrength(unsigned int str)
{
    strength = str;
}

void Adventurer::AddStrength(unsigned int str)
{
    strength += str;
    this->AddMaxHP(str * 2);
}

unsigned int Adventurer::GetAgility()
{
    return agility;
}

void Adventurer::SetAgility(unsigned int agi)
{
    agility = agi;
}

void Adventurer::AddAgility(unsigned int agi)
{
    agility += agi;
}

unsigned int Adventurer::GetIntellect()
{
    return intellect;
}

void Adventurer::SetIntellect(unsigned int intel)
{
    intellect = intel;
}

void Adventurer::AddIntellect(unsigned int intel)
{
    intellect += intel;
    this->AddMaxMP(intel * 3);

}

unsigned int Adventurer::GetTP()
{
    return tp;
}

void Adventurer::SetTP(unsigned int points)
{
    tp = points;
}

void Adventurer::AddTP(unsigned int points)
{
    tp += points;
}

unsigned int Adventurer::GetExperience()
{
    return experience;
}

void Adventurer::SetExperience(unsigned int exp)
{
    experience = exp;
}

void Adventurer::AddExperience(unsigned int exp)
{
    experience += exp;

    while((this->GetLvl() * exp_per_lvl) <= experience)
    {
        experience -= (this->GetLvl() * exp_per_lvl);
        LevelUp();
    }
}

void Adventurer::LevelUp()
{
    this->AddLvl(1);
    this->AddMaxHP(10);
    this->AddMaxMP(5);
    
    AddStrength(1);
    AddAgility(1);
    AddIntellect(1);
    AddTP(tp_per_lvl);
}

Adventurer::Adventurer()
{
    this->SetLvl(1);
    this->SetMaxHP(100);
    this->SetCurrentHP(100);
    this->SetMaxMP(50);
    this->SetCurrentMP(50);
    strength = 10;
    agility = 10;
    intellect = 10;
    tp = 10;
    experience = 0;
};