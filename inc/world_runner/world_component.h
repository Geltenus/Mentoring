#pragma once

enum WorldComponentType
{
    WCT_STARTING = 0,
    WCT_WALKING,
    WCT_INVENTORY,
    WCT_FIGHTING,
    WCT_USER_INPUT
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
