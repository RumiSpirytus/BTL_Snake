#include "Snake.hpp"
#include "Defs.hpp"
#include "Game.hpp"

Snake::Snake()
{
    dir = Direction::right;
}
Snake::~Snake()
{
    //
}

bool Snake::Loadmedia()
{

    std::unique_ptr<Object> body = std::make_unique<Object>();
    body->loadMedia(SNAKE_HEAD_IMAGE);
    body->setPosition(11 * 16, 0);
    list_snake.push_back(std::move(body));
    for (int i = 0; i < 11; i++)
    {
        std::unique_ptr<Object> body = std::make_unique<Object>();
        body->loadMedia(SNAKE_IMAGE_PATH);
        body->setPosition(16 * (10 - i), 0);
        list_snake.push_back(std::move(body));
    }
    a.loadMedia();
    w.loadMedia();
    return true;
}

void Snake::HandleInputAction(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_d:
            dir = Direction::right;
            break;
        case SDLK_a:
            dir = Direction::left;
            break;
        case SDLK_w:
            dir = Direction::up;
            break;
        case SDLK_s:
            dir = Direction::down;
            break;
        case SDLK_SPACE:
            a.genarateApple();
        default:
            break;
        }
    }
}

void Snake::Update()
{
    for (int i = list_snake.size() - 1; i > 0; i--)
    {
        list_snake[i]->setPosition(list_snake[i - 1]->getPosition().first, list_snake[i - 1]->getPosition().second);
    }
    std::pair<int, int> head = list_snake[0]->getPosition();
    if (dir == Direction::up)
    {
        head.second -= 16;
    }
    else if (dir == Direction::down)
    {
        head.second += 16;
    }
    else if (dir == Direction::right)
    {
        head.first += 16;
    }
    else if (dir == Direction::left)
    {
        head.first -= 16;
    }
    // Wall
    if (head.first == SCREEN_WIDTH)
    {
        head.first = 0;
    }
    else if (head.first == -16)
    {
        head.first = SCREEN_WIDTH;
    }
    else if (head.second == SCREEN_HEIGHT)
    {
        head.second = 0;
    }
    else if (head.second == -16)
    {
        head.second = SCREEN_HEIGHT;
    }
    // update head
    list_snake[0]->setPosition(head.first, head.second);
    //
    if (checkColisionSnakeWithApple())
    {
        a.genarateApple();
        growSnake();
    }
}

void Snake::growSnake()
{
    std::unique_ptr<Object> body = std::make_unique<Object>();
    body->loadMedia(SNAKE_IMAGE_PATH);
    body->setPosition(-16, -16);
    list_snake.push_back(std::move(body));
}

void Snake::DrawSnake()
{
    for (int i = 0; i < list_snake.size(); i++)
    {
        list_snake[i]->draw();
    }
    a.draw();
    w.draw();
    // std::cout << list_snake.size() << std::endl;
}