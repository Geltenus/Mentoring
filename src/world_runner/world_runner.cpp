#include <map>
#include <iostream>
#include "world_runner.h"
#include "action.h"

#if __linux__
#include <ncurses.h>
#elif _WIN32
#include <conio.h>
#else
#error "Wrong OS"
#endif

std::map<char, IAction *> fightingActions;
Action Test1('1');
Action Test2('2');
Action Test3('3');
Action Test4('4');
Action Test5('5');
Action Test6('6');

WorldComponentType WorldComponentBase::GetType()
{
    return _type;
};

void WorldComponentBase::SetType(WorldComponentType type)
{
    _type = type;
};

void WorldComponentBase::SetMediator(IWorldRunnerMediator *wr)
{
    _wr = wr;
}

char UserInput::WaitForChar(bool notify)
{
#if __linux__
    initscr(); // Initialize ncurses mode
    cbreak();  // Disable line buffering
    noecho();  // Do not echo input characters
#endif

    char c = getch();

#if __linux__
    endwin(); // End ncurses mode
#endif
    if (true == notify)
    {
        _wr->Notify(*this, c);
    }

    return c;
}

UserInput::UserInput()
{
    WorldComponentBase::_type = WorldComponentType::USER_INPUT;
}

void WorldRunner::Notify(WorldComponentBase &component, char event)
{
    if (event == 'q')
    {
        _running = false;
        return;
    }

    switch (component.GetType())
    {
    case WorldComponentType::STARTING:
    {
        // TODO
    }
    break;

    case WorldComponentType::WALKING:
    {
        // TODO
    }
    break;

    case WorldComponentType::INVENTORY:
    {
        // TODO
    }
    break;

    case WorldComponentType::FIGHTING:
    {
        auto it = fightingActions.find(event);

        if (it != fightingActions.end())
        {
            FightPlaneBuilder plane(_tui, _a, _e);
            RenderPlane(_tui, plane);
            it->second->Execute(_tui);
        }
    }
    break;

    case WorldComponentType::USER_INPUT:
        switch (event)
        {
        case '1':
        {
            WalkPlaneBuilder plane(_tui, _a);
            RenderPlane(_tui, plane);
            break;
        }
        case '2':
        {
            EnterFight(component);
            break;
        }
        case '3':
        {
            InventoryPlaneBuilder plane(_tui, _a);
            RenderPlane(_tui, plane);
            break;
        }
        default:
            break;
        }
    }
}

void WorldRunner::Run(void)
{
    _running = true;

    while (_running)
    {
        _user_input->WaitForChar();
    }
}

WorldRunner::WorldRunner(UserInput *user_input, TUI &tui, Adventurer &a, Being &e) : _user_input(user_input), _tui(tui), _a(a), _e(e)
{
    _user_input->SetMediator(this);
    InitFighting();
}

void WorldRunner::RenderPlane(TUI &tui, IPlaneBuilder &plane)
{
    PlaneBuilder builder;

    tui.ClearTUI();

    builder.Build(plane);

    tui.RenderTUI();
}

void WorldRunner::InitFighting(void)
{
    fightingActions['1'] = &Test1;
    fightingActions['2'] = &Test2;
    fightingActions['3'] = &Test3;
    fightingActions['4'] = &Test4;
    fightingActions['5'] = &Test5;
    fightingActions['6'] = &Test6;
}

void WorldRunner::EnterFight(WorldComponentBase &component)
{
    component.SetType(WorldComponentType::FIGHTING);

    FightPlaneBuilder plane(_tui, _a, _e);
    RenderPlane(_tui, plane);
}

void WorldRunner::EnterStart(void)
{
}

void WorldRunner::EnterWalk(void)
{
}

void WorldRunner::EnterInventory(void)
{
}

void WorldRunner::EnterUserInput(void)
{
}