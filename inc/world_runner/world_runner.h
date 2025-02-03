#pragma once

#include <string>
#include "tui.h"
#include "adventurer.h"
#include "being.h"
#include "plane_builder.h"

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
    WorldComponentType GetType() { return _type; };
    void SetMediator(IWorldRunnerMediator *wr)
    {
        _wr = wr;
    }

protected:
    IWorldRunnerMediator *_wr;
    WorldComponentType _type;
};

class UserInput : public WorldComponentBase
{
public:
    void WaitForChar(void);
};

class WorldRunner : public IWorldRunnerMediator
{
public:
    void Notify(WorldComponentBase &component, char event);
    void Run(void);

    WorldRunner(UserInput *user_input, TUI &tui, Adventurer &a, Being &e) : _user_input(user_input), _tui(tui), _a(a), _e(e)
    {
        _user_input->SetMediator(this);
    }

private:
    bool _running;
    UserInput *_user_input;
    TUI &_tui;
    Adventurer &_a;
    Being &_e;

    void RenderPlane(TUI &tui, IPlaneBuilder &plane);
};