#include <iostream>
#include <vector>
#include <string>
#include "renderer.h"

// Special instructions
const static std::string RESET_POSITION = "\033[H"; /* Reset cursor position */
const static std::string NEW_LINE = "\n";           /* New line */

// Colors
const static std::string RESET = "\033[0m"; /* Reset colors to default */

const static std::string BLACK = "\033[30m";   /* Black */
const static std::string RED = "\033[31m";     /* Red */
const static std::string GREEN = "\033[32m";   /* Green */
const static std::string YELLOW = "\033[33m";  /* Yellow */
const static std::string BLUE = "\033[34m";    /* Blue */
const static std::string MAGENTA = "\033[35m"; /* Magenta */
const static std::string CYAN = "\033[36m";    /* Cyan */
const static std::string GREY = "\033[37m";    /* Grey */

const static std::string BG_BLACK = "\033[40m";   /* Background Black */
const static std::string BG_RED = "\033[41m";     /* Background Red */
const static std::string BG_GREEN = "\033[42m";   /* Background Green */
const static std::string BG_YELLOW = "\033[43m";  /* Background Yellow */
const static std::string BG_BLUE = "\033[44m";    /* Background Blue */
const static std::string BG_MAGENTA = "\033[45m"; /* Background Magenta */
const static std::string BG_CYAN = "\033[46m";    /* Background Cyan */
const static std::string BG_GREY = "\033[47m";    /* Background Grey */

const static std::string BOLD_BLACK = "\033[1m\033[30m";   /* Bold Black */
const static std::string BOLD_RED = "\033[1m\033[31m";     /* Bold Red */
const static std::string BOLD_GREEN = "\033[1m\033[32m";   /* Bold Green */
const static std::string BOLD_YELLOW = "\033[1m\033[33m";  /* Bold Yellow */
const static std::string BOLD_BLUE = "\033[1m\033[34m";    /* Bold Blue */
const static std::string BOLD_MAGENTA = "\033[1m\033[35m"; /* Bold Magenta */
const static std::string BOLD_CYAN = "\033[1m\033[36m";    /* Bold Cyan */
const static std::string BOLD_GREY = "\033[1m\033[37m";    /* Bold Grey */

const static std::string BG_BOLD_BLACK = "\033[1m\033[40m";   /* Background Bold Black */
const static std::string BG_BOLD_RED = "\033[1m\033[41m";     /* Background Bold Red */
const static std::string BG_BOLD_GREEN = "\033[1m\033[42m";   /* Background Bold Green */
const static std::string BG_BOLD_YELLOW = "\033[1m\033[43m";  /* Background Bold Yellow */
const static std::string BG_BOLD_BLUE = "\033[1m\033[44m";    /* Background Bold Blue */
const static std::string BG_BOLD_MAGENTA = "\033[1m\033[45m"; /* Background Bold Magenta */
const static std::string BG_BOLD_CYAN = "\033[1m\033[46m";    /* Background Bold Cyan */
const static std::string BG_BOLD_GREY = "\033[1m\033[47m";    /* Background Bold Grey */

std::vector<std::string> colors(ColorType::MAX_COLOR);

void InitRenderer()
{
    colors[ColorType::Default] = RESET;
    colors[ColorType::Black] = BLACK;
    colors[ColorType::Red] = RED;
    colors[ColorType::Green] = GREEN;
    colors[ColorType::Yellow] = YELLOW;
    colors[ColorType::Blue] = BLUE;
    colors[ColorType::Magenta] = MAGENTA;
    colors[ColorType::Cyan] = CYAN;
    colors[ColorType::Grey] = GREY;

    colors[ColorType::BG_Black] = BG_BLACK;
    colors[ColorType::BG_Red] = BG_RED;
    colors[ColorType::BG_Green] = BG_GREEN;
    colors[ColorType::BG_Yellow] = BG_YELLOW;
    colors[ColorType::BG_Blue] = BG_BLUE;
    colors[ColorType::BG_Magenta] = BG_MAGENTA;
    colors[ColorType::BG_Cyan] = BG_CYAN;
    colors[ColorType::BG_Grey] = BG_GREY;

    colors[ColorType::Bold_Black] = BOLD_BLACK;
    colors[ColorType::Bold_Red] = BOLD_RED;
    colors[ColorType::Bold_Green] = BOLD_GREEN;
    colors[ColorType::Bold_Yellow] = BOLD_YELLOW;
    colors[ColorType::Bold_Blue] = BOLD_BLUE;
    colors[ColorType::Bold_Magenta] = BOLD_MAGENTA;
    colors[ColorType::Bold_Cyan] = BOLD_CYAN;
    colors[ColorType::Bold_Grey] = BOLD_GREY;

    colors[ColorType::BG_Bold_Black] = BG_BOLD_BLACK;
    colors[ColorType::BG_Bold_Red] = BG_BOLD_RED;
    colors[ColorType::BG_Bold_Green] = BG_BOLD_GREEN;
    colors[ColorType::BG_Bold_Yellow] = BG_BOLD_YELLOW;
    colors[ColorType::BG_Bold_Blue] = BG_BOLD_BLUE;
    colors[ColorType::BG_Bold_Magenta] = BG_BOLD_MAGENTA;
    colors[ColorType::BG_Bold_Cyan] = BG_BOLD_CYAN;
    colors[ColorType::BG_Bold_Grey] = BG_BOLD_GREY;
}

std::string SetColor(ColorType type)
{
    return colors[type];
}

void Renderer::ClearInputLine(void)
{
    std::string inputLine(Y, ' ');
    inputLine += '\r';

    std::cout << inputLine;
}

void Renderer::ClearChars(void)
{
    for (unsigned int x = 0; x <= X; x++)
    {
        for (unsigned int y = 0; y < Y; y++)
        {
            SetChar(x, y, filler, ColorType::Default);
        }
    }
}

void Renderer::ClearScreen(bool reset_pos)
{
    // Clear buffer
    screen.clear();

    if (reset_pos == true)
    {
        screen += RESET_POSITION;
    }

    for (unsigned int x = 0; x <= 2 * X; x++)
    {
        for (unsigned int y = 0; y < 2 * Y; y++)
        {
            screen += ' ';
        }

        screen += NEW_LINE;
    }

    if (reset_pos == true)
    {
        screen += RESET_POSITION;
    }

    std::cout << screen;

    // Clear buffer
    screen.clear();
}


void Renderer::SetChar(unsigned int x, unsigned int y, char c, ColorType color)
{
    if ((x < X) && (y < Y))
    {
        chars[x][y].text = c;
        chars[x][y].color = color;
    }
}

void Renderer::Print(void)
{
    static ColorType last_color = Default;

    // ClearScreen(true);
    screen += RESET_POSITION;

    // Prepare buffer
    for (unsigned int x = 0; x < X; x++)
    {
        for (unsigned int y = 0; y < Y; y++)
        {
            if (last_color != chars[x][y].color)
            {
                last_color = chars[x][y].color;
                screen += SetColor(last_color);
            }

            screen += chars[x][y].text;
        }

        screen += NEW_LINE;
    }

    last_color = ColorType::Default;

    std::cout << screen;

    ClearInputLine();
}

Renderer::Renderer(char c) : filler(c)
{
    InitRenderer();
    ClearScreen(false);
}