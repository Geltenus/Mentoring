#pragma once

class Being
{
private:
    unsigned int lvl;
    unsigned int max_hp;
    unsigned int max_mp;
    int current_hp;
    int current_mp;

public:
    unsigned int GetLvl()
    {
        return lvl;
    }

    void SetLvl(unsigned int level)
    {
        lvl = level;
    }

    void AddLvl(unsigned int level)
    {
        lvl += level;
    }

    unsigned int GetMaxHP()
    {
        return max_hp;
    }

    void SetMaxHP(unsigned int hp)
    {
        max_hp = hp;
    }

    void AddMaxHP(unsigned int hp)
    {
        max_hp += hp;
    }

    unsigned int GetMaxMP()
    {
        return max_mp;
    }

    void SetMaxMP(unsigned int mp)
    {
        max_mp = mp;
    }

    void AddMaxMP(unsigned int mp)
    {
        max_mp += mp;
    }

    int GetCurrentHP()
    {
        return current_hp;
    }

    void SetCurrentHP(int hp)
    {
        current_hp = hp;
    }

    int GetCurrentMP()
    {
        return current_mp;
    }

    void SetCurrentMP(int mp)
    {
        current_mp = mp;
    }
};