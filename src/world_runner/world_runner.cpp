#include "world_runner.h"

#if __linux__
#include <ncurses.h>
#elif _WIN32
#include <conio.h>
#else
#error "Wrong OS"
#endif

void WorldRunner::Notify(WorldComponent &component, char event)
{
}

void WorldRunner::Run(void)
{
}

char WorldRunner::WaitForChar(void)
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

    return c;
}

void WorldRunner::WaitForChar(char c)
{
#if __linux__
    initscr(); // Initialize ncurses mode
    cbreak();  // Disable line buffering
    noecho();  // Do not echo input characters
#endif

    while (getch() != c)
    {
        // wait for specific key
    }

#if __linux__
    endwin(); // End ncurses mode
#endif
}
