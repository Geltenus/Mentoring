#pragma once

#include "world_component.h"
#include "action.h"
#include "renderer.h"
#include "tui.h"
#include "adventurer.h"
#include "being.h"

class Fight : public WorldComponentBase
{
public:
    Fight();
    bool Execute(char event, TUI &tui, Adventurer &a, Being &e);
};