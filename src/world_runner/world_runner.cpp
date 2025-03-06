#include <map>
#include <iostream>
#include "world_runner.h"
#include "fight.h"

void WorldRunner::Notify(WorldComponentBase &component, char event)
{
    if (event == 'q')
    {
        _running = false;
        return;
    }

    switch (component.GetType())
    {
    case WorldComponentType::WCT_STARTING:
    {
        // TODO
    }
    break;

    case WorldComponentType::WCT_WALKING:
    {
        // TODO
    }
    break;

    case WorldComponentType::WCT_INVENTORY:
    {
        // TODO
    }
    break;

    case WorldComponentType::WCT_FIGHTING:
    {
        // TODO
        Fight fight;

        if (fight.Execute(event, _tui, _a, _e))
        {
        }
    }
    break;

    case WorldComponentType::WCT_USER_INPUT:
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
            _wr_state = WorldRunnerState::WRS_FIGHTING;
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
}

void WorldRunner::RenderPlane(TUI &tui, IPlaneBuilder &plane)
{
    PlaneBuilder builder;

    tui.ClearTUI();

    builder.Build(plane);

    tui.RenderTUI();
}

void WorldRunner::EnterFight(WorldComponentBase &component)
{
    component.SetType(WorldComponentType::WCT_FIGHTING);

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