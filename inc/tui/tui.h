#pragma once

#include <string>
#include "renderer.h"

class TUI
{
public:
    void AddText(Renderer &r, unsigned int x, unsigned int y, std::string s, ColorType color = ColorType::Default);
    void AddReverseText(Renderer &r, unsigned int x, unsigned int y, std::string s, ColorType color = ColorType::Default);
    void AddWrapedText(Renderer &r, unsigned int x, unsigned int y, unsigned int w, std::string s, ColorType color = ColorType::Default);
    void AddProgressBar(Renderer &r, unsigned int x, unsigned int y, unsigned int length, double percent, char c = ' ', ColorType color = ColorType::Default);
    void AddReverseProgressBar(Renderer &r, unsigned int x, unsigned int y, unsigned int length, double percent, char c = ' ', ColorType color = ColorType::Default);
    void ClearTUI(Renderer &r);
    void RenderTUI(Renderer &r);

private:
};