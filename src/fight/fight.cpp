#include <string>
#include <iostream>
#include <map>
#include "fight.h"
#include "tui.h"
#include "plane_builder.h"
#include "renderer.h"

std::map<char, IAction *> fightingActions;
Action Test1('1');
Action Test2('2');
Action Test3('3');
Action Test4('4');
Action Test5('5');
Action Test6('6');

Fight::Fight()
{
    WorldComponentBase::_type = WorldComponentType::WCT_FIGHTING;

    fightingActions['1'] = &Test1;
    fightingActions['2'] = &Test2;
    fightingActions['3'] = &Test3;
    fightingActions['4'] = &Test4;
    fightingActions['5'] = &Test5;
    fightingActions['6'] = &Test6;
}

bool Fight::Execute(char event, TUI &tui, Adventurer &a, Being &e)
{
    auto it = fightingActions.find(event);

    if (it != fightingActions.end())
    {
        PlaneBuilder builder;
        FightPlaneBuilder plane(tui, a, e);

        tui.ClearTUI();
        builder.Build(plane);
        tui.RenderTUI();

        it->second->Execute(tui);
    }

    return false;
}