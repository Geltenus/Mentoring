#pragma once

#include "renderer.h"
#include "tui.h"
#include "adventurer.h"
#include "being.h"

class IPlaneBuilder
{
public:
    virtual void PrepareAdventureBars(TUI &tui, Adventurer &a) final
    {
        std::string tmp_lvl = "LV ";
        tmp_lvl += std::to_string(a.GetLvl());

        tui.AddText(0, 0, tmp_lvl);
        tui.AddText(1, 0, "HP", ColorType::Bold_Red);
        tui.AddText(2, 0, "MP", ColorType::Bold_Blue);
        tui.AddText(3, 0, "EXP", ColorType::Bold_Magenta);
        tui.AddProgressBar(1, 4, 30, static_cast<double>(a.GetCurrentHP()) / static_cast<double>(a.GetMaxHP()), '/', ColorType::Bold_Red, TerminalMode::Underline);
        tui.AddProgressBar(2, 4, 30, static_cast<double>(a.GetCurrentMP()) / static_cast<double>(a.GetMaxMP()), '/', ColorType::Bold_Blue, TerminalMode::Underline);
        tui.AddProgressBar(3, 4, 30, static_cast<double>(a.GetExperience()) / static_cast<double>(a.GetExperienceToNextLvl()), '/', ColorType::Bold_Magenta, TerminalMode::Underline);
    }

    virtual void PrepareEnemyBars(Being &enemy) {}
    virtual void PrepareOptions() {}
    virtual void PrepareDescriptions() {}

    virtual void Build() = 0;
};

class PlaneBuilder
{
public:
    void Build(IPlaneBuilder &plane)
    {
        plane.Build();
    }
};

class FightPlaneBuilder : public IPlaneBuilder
{
public:
    FightPlaneBuilder(TUI &tui, Adventurer &a, Being &e) : _tui(tui), _a(a), _e(e) {};

    void Build()
    {
        PrepareAdventureBars(_tui, _a);
        PrepareEnemyBars(_e);
        PrepareOptions();
    }

private:
    void PrepareEnemyBars(Being &e)
    {
        std::string tmp_lvl = e.GetName() + ", LV ";
        tmp_lvl += std::to_string(e.GetLvl());

        _tui.AddReverseText(0, 99, tmp_lvl);
        _tui.AddText(1, 97, "HP", ColorType::Bold_Red);
        _tui.AddText(2, 97, "MP", ColorType::Bold_Blue);
        _tui.AddReverseProgressBar(1, 99, 30, static_cast<double>(e.GetCurrentHP()) / static_cast<double>(e.GetMaxHP()), '\\', ColorType::Bold_Red, TerminalMode::Underline);
        _tui.AddReverseProgressBar(2, 99, 30, static_cast<double>(e.GetCurrentMP()) / static_cast<double>(e.GetMaxMP()), '\\', ColorType::Bold_Blue, TerminalMode::Underline);
    }

    void PrepareOptions()
    {
        _tui.AddText(24, 0, "1. Attack.");
        _tui.AddText(26, 0, "2. Magic.");
        _tui.AddText(28, 0, "3. Inventory.");
        _tui.AddText(24, 49, "4. Escape");
        _tui.AddText(26, 49, "5. Catch.");
    }

    TUI &_tui;
    Adventurer &_a;
    Being &_e;
};

class WalkPlaneBuilder : public IPlaneBuilder
{
public:
    WalkPlaneBuilder(TUI &tui, Adventurer &a) : _tui(tui), _a(a) {};

    void Build()
    {
        PrepareAdventureBars(_tui, _a);
        PrepareDescriptions();
        PrepareOptions();
    }

private:
    void PrepareEnemyBars(Being &e) {}

    void PrepareOptions()
    {
        _tui.AddText(24, 0, "1. Go NORTH.");
        _tui.AddText(26, 0, "2. Go EAST.");
        _tui.AddText(28, 0, "3. Go WEST.");
        _tui.AddText(24, 49, "4. Go SOUTH.");
        _tui.AddText(26, 49, "5. Rest.");
        _tui.AddText(28, 49, "6. Sleep.");
    }

    void PrepareDescriptions()
    {
        _tui.AddWrapedText(15, ((99 - 40) / 2), 40, "You are inside a forest. All You can see are trees, lots of trees");
    }

    TUI &_tui;
    Adventurer &_a;
};

class InventoryPlaneBuilder : public IPlaneBuilder
{
public:
    InventoryPlaneBuilder(TUI &tui, Adventurer &a) : _tui(tui), _a(a) {};

    void Build()
    {
        PrepareAdventureBars(_tui, _a);
        PrepareDescriptions();
        PrepareOptions();
    }

private:
    void PrepareEnemyBars(Being &e) {}

    void PrepareOptions()
    {
        _tui.AddText(6, 0, "1. Sword.");
        _tui.AddText(8, 0, "2. Wand.");
        _tui.AddText(10, 0, "3. HP Potion.");
        _tui.AddText(12, 0, "4. Caged Rat.");
        _tui.AddText(14, 0, "5. Tent.");
        _tui.AddText(16, 0, "6. Torch.");
    }

    void PrepareDescriptions()
    {
        _tui.AddWrapedText(1, 50, 49, "This Rat was catched by suprise. But be ware! It is furious about being in cage, proceed with caution");
    }

    TUI &_tui;
    Adventurer &_a;
};