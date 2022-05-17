#pragma once
#include "Object.hpp"
#include <Utility>
#include <memory>
#include <vector>
#include "Apple.hpp"
#include "Wall.hpp"
enum class Direction
{
    up,
    down,
    right,
    left
};
class Snake
{
public:
    Snake();
    ~Snake();
    bool Loadmedia();
    void HandleInputAction(SDL_Event event);
    void Update();
    void DrawSnake();
    void growSnake();
    bool checkColisionSnakeWithApple()
    {
        if (list_snake[0]->getPosition().first == a.getApple().first && list_snake[0]->getPosition().second == a.getApple().second)
        {
            return true;
        }
        return false;
    }

private:
    std::vector<std::unique_ptr<Object>> list_snake;
    Direction dir;
    Apple a;
    Wall w;
};
