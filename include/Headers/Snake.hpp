#pragma once
#include "Texture.hpp"
#include <Utility>
class Snake
{
public:
    Snake();
    ~Snake();
    bool Loadmedia();
    void HandleInputAction(SDL_Event event);
    void Update();
    void DrawSnake();

private:
    LTexture snake;
    SDL_Rect snake_clip;
    std::pair<int, int> snake_pos;
    std::pair<int, int> velocity;
};
