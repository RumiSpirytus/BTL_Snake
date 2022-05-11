#include "Snake.hpp"
#include "Defs.hpp"
#include "Game.hpp"
Snake::Snake()
{
    snake_clip = {100, 100, 20, 20};
    snake_pos = std::make_pair(0, 0);
}
Snake::~Snake()
{
    //
}

bool Snake::Loadmedia()
{
    bool success = true;
    if (!snake.loadFromFile(SNAKE_IMAGE_PATH))
    {
        success = false;
    }
    return success;
}

void Snake::HandleInputAction(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_a:
            velocity = std::make_pair(-20, 0);
            break;
        case SDLK_s:
            velocity = std::make_pair(0, 20);
            break;
        case SDLK_w:
            velocity = std::make_pair(0, -20);
            break;
        case SDLK_d:
            velocity = std::make_pair(20, 0);
            break;
        default:
            break;
        }
    }
}

void Snake::Update()
{
    snake_pos.first += velocity.first;
    snake_pos.second += velocity.second;
}

void Snake::DrawSnake()
{
    snake.render(snake_pos.first, snake_pos.second, &snake_clip);
}