#pragma once
#include "Object.hpp"
#include <Utility>
#include <vector>
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
    std::vector<Object> list_snake;
};
