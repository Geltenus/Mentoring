#pragma once

#include <string>
#include "tui.h"
#include "adventurer.h"
#include "being.h"
#include "plane_builder.h"
#include "world_component.h"
#include "user_input.h"
#include "fight.h"

enum WorldRunnerState
{
    WRS_STARTING = 0,
    WRS_WALKING,
    WRS_INVENTORY,
    WRS_FIGHTING,
    WRS_USER_INPUT
};

class WorldRunner : public IWorldRunnerMediator
{
public:
    void Notify(WorldComponentBase &component, char event);
    void Run(void);
    WorldRunner(Fight *fight, UserInput *user_input, TUI &tui, Adventurer &a, Being &e);

private:
    WorldRunnerState _wr_state;
    bool _running;
    UserInput *_user_input;
    Fight *_fight;
    TUI &_tui;
    Adventurer &_a;
    Being &_e;

    void RenderPlane(TUI &tui, IPlaneBuilder &plane);
    void EnterStart(void);
    void EnterWalk(void);
    void EnterInventory(void);
    void EnterFight(WorldComponentBase &component);
    void EnterUserInput(void);

    void CheckUserInputComponent(WorldComponentBase &component, char event);
    void CheckUserInput(WorldComponentBase &component, char event);

    void CheckFightingComponent(WorldComponentBase &component, char event);
    void CheckFighting(WorldComponentBase &component, char event);
};