#pragma once

#include <string>
#include "renderer.h"

class TUI
{
public:
    TUI(Renderer &r) : _r(r) {};
    void AddText(unsigned int x, unsigned int y, const std::string &s, ColorType color = ColorType::Default);
    void AddReverseText(unsigned int x, unsigned int y, const std::string &s, ColorType color = ColorType::Default);
    void AddWrapedText(unsigned int x, unsigned int y, unsigned int w, const std::string &s, ColorType color = ColorType::Default);
    void AddProgressBar(unsigned int x, unsigned int y, unsigned int length, double percent, char c = ' ', ColorType color = ColorType::Default, TerminalMode mode = TerminalMode::Default_Mode);
    void AddReverseProgressBar(unsigned int x, unsigned int y, unsigned int length, double percent, char c = ' ', ColorType color = ColorType::Default, TerminalMode mode = TerminalMode::Default_Mode);
    void ClearTUI();
    void RenderTUI();

private:
    Renderer &_r;
};