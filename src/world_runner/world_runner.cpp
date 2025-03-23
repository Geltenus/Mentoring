#include <map>
#include <iostream>
#include "world_runner.h"
#include "fight.h"

void WorldRunner::CheckUserInputComponent(WorldComponentBase &component, char event)
{
    switch (_wr_state)
    {
    case WorldRunnerState::WRS_STARTING:
    {
    }
    break;

    case WorldRunnerState::WRS_WALKING:
    {
    }
    break;

    case WorldRunnerState::WRS_INVENTORY:
    {
    }
    break;

    case WorldRunnerState::WRS_FIGHTING:
    {
        CheckFighting(component, event);
    }
    break;

    case WorldRunnerState::WRS_USER_INPUT:
    {
        CheckUserInput(component, event);
    }
    break;

    default:
        break;
    }
}

void WorldRunner::CheckUserInput(WorldComponentBase &component, char event)
{
    switch (event)
    {
    case '1':
    {
        WalkPlaneBuilder plane(_tui, _a);
        RenderPlane(_tui, plane);
    }
    break;

    case '2':
    {
        FightPlaneBuilder plane(_tui, _a, _e);
        RenderPlane(_tui, plane);
        EnterFight(component);
    }
    break;

    case '3':
    {
        InventoryPlaneBuilder plane(_tui, _a);
        RenderPlane(_tui, plane);
    }
    break;

    default:
        break;
    }
}

void WorldRunner::CheckFightingComponent(WorldComponentBase &component, char event)
{
    switch (_wr_state)
    {
    case WorldRunnerState::WRS_STARTING:
    {
    }
    break;

    case WorldRunnerState::WRS_WALKING:
    {
    }
    break;

    case WorldRunnerState::WRS_INVENTORY:
    {
    }
    break;

    case WorldRunnerState::WRS_FIGHTING:
    {
    }
    break;

    case WorldRunnerState::WRS_USER_INPUT:
    {
    }
    break;

    default:
        break;
    }
}

void WorldRunner::CheckFighting(WorldComponentBase &component, char event)
{
    Fight fight;

    fight.Execute(event, _tui, _a, _e);
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
        CheckFightingComponent(component, event);
    }
    break;

    case WorldComponentType::WCT_USER_INPUT:
        CheckUserInputComponent(component, event);
    }
}

void WorldRunner::Run(void)
{
    _running = true;
    _wr_state = WorldRunnerState::WRS_USER_INPUT;

    while (_running)
    {
        _user_input->WaitForChar();
    }
}

WorldRunner::WorldRunner(Fight *fight, UserInput *user_input, TUI &tui, Adventurer &a, Being &e) : _fight(fight), _user_input(user_input), _tui(tui), _a(a), _e(e)
{
    _fight->SetMediator(this);
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
    _wr_state = WorldRunnerState::WRS_FIGHTING;
}

void WorldRunner::EnterStart(void)
{
    _wr_state = WorldRunnerState::WRS_STARTING;
}

void WorldRunner::EnterWalk(void)
{
    _wr_state = WorldRunnerState::WRS_WALKING;
}

void WorldRunner::EnterInventory(void)
{
    _wr_state = WorldRunnerState::WRS_INVENTORY;
}

void WorldRunner::EnterUserInput(void)
{
    _wr_state = WorldRunnerState::WRS_USER_INPUT;
}