#pragma once

#include <string>

enum WorldComponentType
{
    STARTING = 0,
    WALKING,
    INVENTORY,
    FIGHTING
};

class WorldComponent;

class IWorldRunnerMediator
{
public:
    virtual void Notify(WorldComponent &component, char event) = 0;
    virtual ~IWorldRunnerMediator() {};
};

class WorldComponentBase
{
public:
    WorldComponentBase(IWorldRunnerMediator &wr, WorldComponentType type) : _wr(wr), _type(type) {};
    WorldComponentType GetType() { return _type; };

private:
    IWorldRunnerMediator &_wr;
    WorldComponentType _type;
};

class WorldRunner : public IWorldRunnerMediator
{
public:
    void Notify(WorldComponent &component, char event);
    void Run(void);
    char WaitForChar(void);
    void WaitForChar(char c);
};