#pragma once

enum ColorType
{
    Default,

    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    Grey,

    BG_Black,
    BG_Red,
    BG_Green,
    BG_Yellow,
    BG_Blue,
    BG_Magenta,
    BG_Cyan,
    BG_Grey,

    Bold_Black,
    Bold_Red,
    Bold_Green,
    Bold_Yellow,
    Bold_Blue,
    Bold_Magenta,
    Bold_Cyan,
    Bold_Grey,

    BG_Bold_Black,
    BG_Bold_Red,
    BG_Bold_Green,
    BG_Bold_Yellow,
    BG_Bold_Blue,
    BG_Bold_Magenta,
    BG_Bold_Cyan,
    BG_Bold_Grey,
};

struct ColoredChar
{
    ColorType color;
    char text;
};

class Renderer
{
private:
    constexpr static unsigned int x = 100;
    constexpr static unsigned int y = 30;
    ColoredChar screen[x][y];
public:
};