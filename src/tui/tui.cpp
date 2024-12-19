#include "tui.h"
#include <iostream>

void TUI::AddText(Renderer &r, unsigned int x, unsigned int y, const std::string &s, ColorType color)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        unsigned int x_temp = x;
        unsigned int y_temp = y;

        y_temp += i;
        if (y_temp > r.Y)
        {
            x_temp += (y_temp / r.Y);
            y_temp %= r.Y;
        }

        r.SetChar(x_temp, y_temp, s.at(i), color);
    }
}

void TUI::AddReverseText(Renderer &r, unsigned int x, unsigned int y, const std::string &s, ColorType color)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        unsigned int x_temp = x;
        unsigned int y_temp = y - s.length() + 1;

        y_temp += i;
        if (y_temp > r.Y)
        {
            x_temp += (y_temp / r.Y);
            y_temp %= r.Y;
        }

        r.SetChar(x_temp, y_temp, s.at(i), color);
    }
}

void TUI::AddWrapedText(Renderer &r, unsigned int x, unsigned int y, unsigned int w, const std::string &s, ColorType color)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        unsigned int x_temp = x + (i / w);
        unsigned int y_temp = y +(i % w);

        r.SetChar(x_temp, y_temp, s.at(i), color);
    }
}

void TUI::AddProgressBar(Renderer &r, unsigned int x, unsigned int y, unsigned int length, double percent, char c, ColorType color)
{
    r.SetChar(x, y, '[', color);
    for (unsigned int i = 0; i < length; i++)
    {
        if ((static_cast<double>(i) / static_cast<double>(length)) <= percent)
        {
            r.SetChar(x, y + i + 1, c, color);
        }
        else
        {
            r.SetChar(x, y + i + 1, ' ', color);
        }
    }
    r.SetChar(x, y + length + 1, ']', color);
}

void TUI::AddReverseProgressBar(Renderer &r, unsigned int x, unsigned int y, unsigned int length, double percent, char c, ColorType color)
{
    r.SetChar(x, y, ']', color);
    for (unsigned int i = 0; i < length; i++)
    {
        if ((static_cast<double>(i) / static_cast<double>(length)) <= percent)
        {
            r.SetChar(x, y - i - 1, c, color);
        }
        else
        {
            r.SetChar(x, y - i - 1, ' ', color);
        }
    }
    r.SetChar(x, y - length - 1, '[', color);
}

void TUI::ClearTUI(Renderer &r)
{
    r.ClearChars();
}

void TUI::RenderTUI(Renderer &r)
{
    r.Print();
}