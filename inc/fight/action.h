#pragma once
#include "tui.h"

class IAction
{
public:
    virtual void Execute(TUI &tui) = 0;
    virtual ~IAction() {};
};

class Action : public IAction
{
public:
    Action(char c);
    void Execute(TUI &tui);

private:
    char _c;
};