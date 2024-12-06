#include <iostream>
#include "renderer.h"

#define RESET "\033[0m" /* Reset colors to default */

#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define GREY "\033[37m"    /* Grey */

#define BG_BLACK "\033[40m"   /* Background Black */
#define BG_RED "\033[41m"     /* Background Red */
#define BG_GREEN "\033[42m"   /* Background Green */
#define BG_YELLOW "\033[43m"  /* Background Yellow */
#define BG_BLUE "\033[44m"    /* Background Blue */
#define BG_MAGENTA "\033[45m" /* Background Magenta */
#define BG_CYAN "\033[46m"    /* Background Cyan */
#define BG_GREY "\033[47m"    /* Background Grey */

#define BOLD_BLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLD_RED "\033[1m\033[31m"     /* Bold Red */
#define BOLD_GREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLD_YELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLD_BLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLD_MAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLD_CYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLD_GREY "\033[1m\033[37m"    /* Bold Grey */

#define BG_BOLD_BLACK "\033[1m\033[40m"   /* Background Bold Black */
#define BG_BOLD_RED "\033[1m\033[41m"     /* Background Bold Red */
#define BG_BOLD_GREEN "\033[1m\033[42m"   /* Background Bold Green */
#define BG_BOLD_YELLOW "\033[1m\033[43m"  /* Background Bold Yellow */
#define BG_BOLD_BLUE "\033[1m\033[44m"    /* Background Bold Blue */
#define BG_BOLD_MAGENTA "\033[1m\033[45m" /* Background Bold Magenta */
#define BG_BOLD_CYAN "\033[1m\033[46m"    /* Background Bold Cyan */
#define BG_BOLD_GREY "\033[1m\033[47m"    /* Background Bold Grey */

void SetColor(ColorType type)
{
    switch (type)
    {
    case ColorType::Default:
        std::cout << RESET;
        break;

    case ColorType::Black:
        std::cout << BLACK;
        break;
    case ColorType::Red:
        std::cout << RED;
        break;
    case ColorType::Green:
        std::cout << GREEN;
        break;
    case ColorType::Yellow:
        std::cout << YELLOW;
        break;
    case ColorType::Blue:
        std::cout << BLUE;
        break;
    case ColorType::Magenta:
        std::cout << MAGENTA;
        break;
    case ColorType::Cyan:
        std::cout << CYAN;
        break;
    case ColorType::Grey:
        std::cout << GREY;
        break;

    case ColorType::BG_Black:
        std::cout << BG_BLACK;
        break;
    case ColorType::BG_Red:
        std::cout << BG_RED;
        break;
    case ColorType::BG_Green:
        std::cout << BG_GREEN;
        break;
    case ColorType::BG_Yellow:
        std::cout << BG_YELLOW;
        break;
    case ColorType::BG_Blue:
        std::cout << BG_BLUE;
        break;
    case ColorType::BG_Magenta:
        std::cout << BG_MAGENTA;
        break;
    case ColorType::BG_Cyan:
        std::cout << BG_CYAN;
        break;
    case ColorType::BG_Grey:
        std::cout << BG_GREY;
        break;

    case ColorType::Bold_Black:
        std::cout << BOLD_BLACK;
        break;
    case ColorType::Bold_Red:
        std::cout << BOLD_RED;
        break;
    case ColorType::Bold_Green:
        std::cout << BOLD_GREEN;
        break;
    case ColorType::Bold_Yellow:
        std::cout << BOLD_YELLOW;
        break;
    case ColorType::Bold_Blue:
        std::cout << BOLD_BLUE;
        break;
    case ColorType::Bold_Magenta:
        std::cout << BOLD_MAGENTA;
        break;
    case ColorType::Bold_Cyan:
        std::cout << BOLD_CYAN;
        break;
    case ColorType::Bold_Grey:
        std::cout << BOLD_GREY;
        break;

    case ColorType::BG_Bold_Black:
        std::cout << BG_BOLD_BLACK;
        break;
    case ColorType::BG_Bold_Red:
        std::cout << BG_BOLD_RED;
        break;
    case ColorType::BG_Bold_Green:
        std::cout << BG_BOLD_GREEN;
        break;
    case ColorType::BG_Bold_Yellow:
        std::cout << BG_BOLD_YELLOW;
        break;
    case ColorType::BG_Bold_Blue:
        std::cout << BG_BOLD_BLUE;
        break;
    case ColorType::BG_Bold_Magenta:
        std::cout << BG_BOLD_MAGENTA;
        break;
    case ColorType::BG_Bold_Cyan:
        std::cout << BG_BOLD_CYAN;
        break;
    case ColorType::BG_Bold_Grey:
        std::cout << BG_BOLD_GREY;
        break;
    }
}