#pragma once
#include "Texture.hpp"
#include <utility>
class Object
{
private:
    LTexture ob_texture;
    std::pair<int, int> pos;
    SDL_Rect clip;

public:
    Object();
    ~Object();
    void loadMedia(std::string path);
    void setPosition(int u, int v)
    {
        pos = std::make_pair(u, v);
    }
    void setRect(int a, int b, int w, int h)
    {
        clip = {a, b, w, h};
    }
    SDL_Rect getRect()
    {
        return {pos.first, pos.second, clip.w, clip.h};
    }
    void draw()
    {
        ob_texture.render(pos.first, pos.second, &clip);
    }
};