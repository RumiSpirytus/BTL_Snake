#pragma once
#include "Texture.hpp"
#include <utility>
class Object
{
private:
        std::pair<int, int> pos;
    SDL_Rect clip;

public:
    LTexture ob_texture;
    Object();
    ~Object();
    void spawn();
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
    std::pair<int, int> getPosition()
    {
        return pos;
    }
    void draw()
    {
        ob_texture.render(pos.first, pos.second, &clip);
    }
};