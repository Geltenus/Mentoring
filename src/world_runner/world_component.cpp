#include "world_component.h"

WorldComponentType WorldComponentBase::GetType()
{
    return _type;
};

void WorldComponentBase::SetType(WorldComponentType type)
{
    _type = type;
}

void WorldComponentBase::SetMediator(IWorldRunnerMediator *wr)
{
    _wr = wr;
}