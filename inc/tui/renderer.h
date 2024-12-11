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

    MAX_COLOR
};

class Renderer
{
public:
    constexpr static unsigned int X = 30;
    constexpr static unsigned int Y = 100;

    Renderer(char c = ' ');
    void Print(void);
    void SetChar(unsigned int x, unsigned int y, char c, ColorType color = ColorType::Default);
    void ClearChars(void);

private:
    char filler;

    struct ColoredChar
    {
        ColorType color;
        char text;
    } chars[X][Y];

    std::string screen;
    
    void ClearScreen(bool reset_pos);
    void ClearInputLine(void);
};