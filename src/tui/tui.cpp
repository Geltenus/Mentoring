#include "tui.h"
#include <iostream>

void TUI::AddText(unsigned int x, unsigned int y, const std::string &s, ColorType color)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        unsigned int x_temp = x;
        unsigned int y_temp = y;

        y_temp += i;
        if (y_temp > _r.Y)
        {
            x_temp += (y_temp / _r.Y);
            y_temp %= _r.Y;
        }

        _r.SetChar(x_temp, y_temp, s.at(i), color);
    }
}

void TUI::AddReverseText(unsigned int x, unsigned int y, const std::string &s, ColorType color)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        unsigned int x_temp = x;
        unsigned int y_temp = y - s.length() + 1;

        y_temp += i;
        if (y_temp > _r.Y)
        {
            x_temp += (y_temp / _r.Y);
            y_temp %= _r.Y;
        }

        _r.SetChar(x_temp, y_temp, s.at(i), color);
    }
}

void TUI::AddWrapedText(unsigned int x, unsigned int y, unsigned int w, const std::string &s, ColorType color)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        unsigned int x_temp = x + (i / w);
        unsigned int y_temp = y + (i % w);

        _r.SetChar(x_temp, y_temp, s.at(i), color);
    }
}

void TUI::AddProgressBar(unsigned int x, unsigned int y, unsigned int length, double percent, char c, ColorType color, TerminalMode mode)
{
    _r.SetChar(x, y, '[', color);
    for (unsigned int i = 0; i < length; i++)
    {
        if ((static_cast<double>(i) / static_cast<double>(length)) < percent)
        {
            _r.SetChar(x, y + i + 1, c, color, mode);
        }
        else
        {
            _r.SetChar(x, y + i + 1, ' ', color, mode);
        }
    }
    _r.SetChar(x, y + length + 1, ']', color);
}

void TUI::AddReverseProgressBar(unsigned int x, unsigned int y, unsigned int length, double percent, char c, ColorType color, TerminalMode mode)
{
    _r.SetChar(x, y, ']', color);
    for (unsigned int i = 0; i < length; i++)
    {
        if ((static_cast<double>(i) / static_cast<double>(length)) < percent)
        {
            _r.SetChar(x, y - i - 1, c, color, mode);
        }
        else
        {
            _r.SetChar(x, y - i - 1, ' ', color, mode);
        }
    }
    _r.SetChar(x, y - length - 1, '[', color);
}

void TUI::ClearTUI()
{
    _r.ClearChars();
}

void TUI::RenderTUI()
{
    _r.Print();
}