#include "Snake.hpp"
#include "Defs.hpp"
#include "Game.hpp"
Snake::Snake()
{
}
Snake::~Snake()
{
    //
}

bool Snake::Loadmedia()
{
    Object x;
    x.loadMedia(SNAKE_IMAGE_PATH);
    list_snake.push_back(x);
    return true;
}

void Snake::HandleInputAction(SDL_Event event)
{
}

void Snake::Update()
{
}

void Snake::DrawSnake()
{
    list_snake[0].draw();
}