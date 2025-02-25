#pragma once

#include <string>
#include "tui.h"
#include "adventurer.h"
#include "being.h"
#include "plane_builder.h"
#include "action.h"

enum WorldComponentType
{
    STARTING = 0,
    WALKING,
    INVENTORY,
    FIGHTING,
    USER_INPUT
};

class WorldComponentBase;

class IWorldRunnerMediator
{
public:
    virtual void Notify(WorldComponentBase &component, char event) = 0;
    virtual ~IWorldRunnerMediator() {};
};

class WorldComponentBase
{
public:
    WorldComponentType GetType();
    void SetType(WorldComponentType type);
    void SetMediator(IWorldRunnerMediator *wr);

protected:
    IWorldRunnerMediator *_wr;
    WorldComponentType _type;
};

class UserInput : public WorldComponentBase
{
public:
    char WaitForChar(bool notify = true);
    UserInput();
};

class WorldRunner : public IWorldRunnerMediator
{
public:
    void Notify(WorldComponentBase &component, char event);
    void Run(void);
    WorldRunner(UserInput *user_input, TUI &tui, Adventurer &a, Being &e);

private:
    bool _running;
    UserInput *_user_input;
    TUI &_tui;
    Adventurer &_a;
    Being &_e;

    void RenderPlane(TUI &tui, IPlaneBuilder &plane);
    void EnterStart(void);
    void EnterWalk(void);
    void EnterInventory(void);
    void EnterFight(WorldComponentBase &component);
    void InitFighting(void);
    void EnterUserInput(void);
};