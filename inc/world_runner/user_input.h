#pragma once

#include "world_component.h"

class UserInput : public WorldComponentBase
{
public:
    char WaitForChar(bool notify = true);
    UserInput();
};