#include "user_input.h"

#if __linux__
#include <ncurses.h>
#elif _WIN32
#include <conio.h>
#else
#error "Wrong OS"
#endif

char UserInput::WaitForChar(bool notify)
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
    if (true == notify)
    {
        _wr->Notify(*this, c);
    }

    return c;
}

UserInput::UserInput()
{
    WorldComponentBase::_type = WorldComponentType::WCT_USER_INPUT;
}