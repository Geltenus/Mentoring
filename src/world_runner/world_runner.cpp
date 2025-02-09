#include "world_runner.h"

#if __linux__
#include <ncurses.h>
#elif _WIN32
#include <conio.h>
#else
#error "Wrong OS"
#endif

WorldComponentType WorldComponentBase::GetType()
{
    return _type;
};

void WorldComponentBase::SetMediator(IWorldRunnerMediator *wr)
{
    _wr = wr;
}

void UserInput::WaitForChar(void)
{
#if __linux__
    initscr(); // Initialize ncurses mode
    cbreak();  // Disable line buffering
    noecho();  // Do not echo input characters
#endif

    char c = getch();

#if __linux__
    endwin(); // End ncurses mode
#endif

    _wr->Notify(*this, c);
}

void WorldRunner::Notify(WorldComponentBase &component, char event)
{
    switch (event)
    {
    case 'q':
    {
        _running = false;
        break;
    }
    case '1':
    {
        WalkPlaneBuilder plane(_tui, _a);
        RenderPlane(_tui, plane);
        break;
    }
    case '2':
    {
        FightPlaneBuilder plane(_tui, _a, _e);
        RenderPlane(_tui, plane);
        break;
    }
    case '3':
    {
        InventoryPlaneBuilder plane(_tui, _a);
        RenderPlane(_tui, plane);
        break;
    }
    default:
        break;
    }
}

void WorldRunner::Run(void)
{
    _running = true;

    while (_running)
    {
        _user_input->WaitForChar();
    }
}

WorldRunner::WorldRunner(UserInput *user_input, TUI &tui, Adventurer &a, Being &e) : _user_input(user_input), _tui(tui), _a(a), _e(e)
{
    _user_input->SetMediator(this);
}

void WorldRunner::RenderPlane(TUI &tui, IPlaneBuilder &plane)
{
    PlaneBuilder builder;

    tui.ClearTUI();

    builder.Build(plane);

    tui.RenderTUI();
}
