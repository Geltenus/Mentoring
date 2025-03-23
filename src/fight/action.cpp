#include <string>
#include <iostream>
#include "action.h"
#include "tui.h"

Action::Action(char c) : _c(c)
{
}

void Action::Execute(TUI &tui)
{
    std::string s(1, _c);
    tui.AddText(14, 49, s);
    tui.RenderTUI();
}