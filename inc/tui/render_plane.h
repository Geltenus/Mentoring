#include "renderer.h"
#include "tui.h"
#include "adventurer.h"
#include "being.h"

class IRenderPlane
{
public:
    virtual void PrepareAdventureBars(Renderer &r, TUI &tui, Adventurer &a) final
    {
        std::string tmp_lvl = "LV ";
        tmp_lvl += std::to_string(a.GetLvl());

        tui.AddText(r, 0, 0, tmp_lvl);
        tui.AddText(r, 1, 0, "HP", ColorType::Bold_Red);
        tui.AddText(r, 2, 0, "MP", ColorType::Bold_Blue);
        tui.AddText(r, 3, 0, "EXP", ColorType::Bold_Magenta);
        tui.AddProgressBar(r, 1, 4, 30, static_cast<double>(a.GetCurrentHP()) / static_cast<double>(a.GetMaxHP()), '/', ColorType::Bold_Red, TerminalMode::Underline);
        tui.AddProgressBar(r, 2, 4, 30, static_cast<double>(a.GetCurrentMP()) / static_cast<double>(a.GetMaxMP()), '/', ColorType::Bold_Blue, TerminalMode::Underline);
        tui.AddProgressBar(r, 3, 4, 30, static_cast<double>(a.GetExperience()) / static_cast<double>(a.GetExperienceToNextLvl()), '/', ColorType::Bold_Magenta, TerminalMode::Underline);
    }

    virtual void PrepareEnemyBars(Being &enemy) {}
    virtual void PrepareOptions() {}
    virtual void PrepareDescriptions() {}

    virtual void Render() = 0;
};

class RenderPlane
{
public:
    void Render(IRenderPlane &plane)
    {
        plane.Render();
    }
};

class RenderFightPlane : public IRenderPlane
{
public:
    RenderFightPlane(Renderer &r, TUI &tui, Adventurer &a, Being &e) : _r(r), _tui(tui), _a(a), _e(e) {};

    void Render()
    {
        _tui.ClearTUI(_r);

        PrepareAdventureBars(_r, _tui, _a);
        PrepareEnemyBars(_e);
        PrepareOptions();

        _tui.RenderTUI(_r);
    }

private:
    void PrepareEnemyBars(Being &e)
    {
        std::string tmp_lvl = e.GetName() + ", LV ";
        tmp_lvl += std::to_string(e.GetLvl());

        _tui.AddReverseText(_r, 0, 99, tmp_lvl);
        _tui.AddText(_r, 1, 97, "HP", ColorType::Bold_Red);
        _tui.AddText(_r, 2, 97, "MP", ColorType::Bold_Blue);
        _tui.AddReverseProgressBar(_r, 1, 99, 30, static_cast<double>(e.GetCurrentHP()) / static_cast<double>(e.GetMaxHP()), '\\', ColorType::Bold_Red, TerminalMode::Underline);
        _tui.AddReverseProgressBar(_r, 2, 99, 30, static_cast<double>(e.GetCurrentMP()) / static_cast<double>(e.GetMaxMP()), '\\', ColorType::Bold_Blue, TerminalMode::Underline);
    }

    void PrepareOptions()
    {
        _tui.AddText(_r, 24, 0, "1. Attack.");
        _tui.AddText(_r, 26, 0, "2. Magic.");
        _tui.AddText(_r, 28, 0, "3. Inventory.");
        _tui.AddText(_r, 24, 49, "4. Escape");
        _tui.AddText(_r, 26, 49, "5. Catch.");
    }

    Renderer &_r;
    TUI &_tui;
    Adventurer &_a;
    Being &_e;
};

class RenderWalkPlane : public IRenderPlane
{
public:
    RenderWalkPlane(Renderer &r, TUI &tui, Adventurer &a) : _r(r), _tui(tui), _a(a) {};

    void Render()
    {
        _tui.ClearTUI(_r);

        PrepareAdventureBars(_r, _tui, _a);
        PrepareDescriptions();
        PrepareOptions();

        _tui.RenderTUI(_r);
    }

private:
    void PrepareEnemyBars(Being &e) {}

    void PrepareOptions()
    {
        _tui.AddText(_r, 24, 0, "1. Go NORTH.");
        _tui.AddText(_r, 26, 0, "2. Go EAST.");
        _tui.AddText(_r, 28, 0, "3. Go WEST.");
        _tui.AddText(_r, 24, 49, "4. Go SOUTH.");
        _tui.AddText(_r, 26, 49, "5. Rest.");
        _tui.AddText(_r, 28, 49, "6. Sleep.");
    }

    void PrepareDescriptions()
    {
        _tui.AddWrapedText(_r, 15, ((99 - 40) / 2), 40, "You are inside a forest. All You can see are trees, lots of trees");
    }

    Renderer &_r;
    TUI &_tui;
    Adventurer &_a;
};

class RenderInventoryPlane : public IRenderPlane
{
public:
    RenderInventoryPlane(Renderer &r, TUI &tui, Adventurer &a) : _r(r), _tui(tui), _a(a) {};

    void Render()
    {
        _tui.ClearTUI(_r);

        PrepareAdventureBars(_r, _tui, _a);
        PrepareDescriptions();
        PrepareOptions();

        _tui.RenderTUI(_r);
    }

private:
    void PrepareEnemyBars(Being &e) {}

    void PrepareOptions()
    {
        _tui.AddText(_r, 6, 0, "1. Sword.");
        _tui.AddText(_r, 8, 0, "2. Wand.");
        _tui.AddText(_r, 10, 0, "3. HP Potion.");
        _tui.AddText(_r, 12, 0, "4. Caged Rat.");
        _tui.AddText(_r, 14, 0, "5. Tent.");
        _tui.AddText(_r, 16, 0, "6. Torch.");
    }

    void PrepareDescriptions()
    {
        _tui.AddWrapedText(_r, 1, 50, 49, "This Rat was catched by suprise. But be ware! It is furious about being in cage, proceed with caution");
    }

    Renderer &_r;
    TUI &_tui;
    Adventurer &_a;
};