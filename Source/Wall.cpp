#include "Wall.hpp"
#include "Defs.hpp"
Wall::Wall()
{
    //
}
Wall::~Wall()
{
    //
}
void Wall::loadMedia()
{
    for (int i = 0; i <= 10; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL1_IMAGE_PATH);
        k->setPosition(16 * i, 16 * 16);
        wall.push_back(std::move(k));
    }
    for (int i = 0; i <= 10; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL2_IMAGE_PATH);
        k->setPosition(16 * 32, 16 * i);
        wall.push_back(std::move(k));
    }
    for (int i = 20; i <= 29; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL3_IMAGE_PATH);
        k->setPosition(16 * 30, 16 * i);
        wall.push_back(std::move(k));
    }
    for (int i = 20; i <= 30; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL3_IMAGE_PATH);
        k->setPosition(16 * i, 30 * 16);
        wall.push_back(std::move(k));
    }
    for (int i = 40; i <= 52; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL2_IMAGE_PATH);
        k->setPosition(16 * i, 26 * 16);
        wall.push_back(std::move(k));
    }
    for (int i = 38; i <= 46; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL3_IMAGE_PATH);
        k->setPosition(32 * 16, 16 * i);
        wall.push_back(std::move(k));
    }
    for (int i = 52; i <= 63; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL4_IMAGE_PATH);
        k->setPosition(i * 16, 16 * 16);
        wall.push_back(std::move(k));
    }
    for (int i = 56; i <= 65; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL3_IMAGE_PATH);
        k->setPosition(i * 16, 16 * 40);
        wall.push_back(std::move(k));
    }
    for (int i = 70; i <= 82; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL4_IMAGE_PATH);
        k->setPosition(i * 16, 16 * 46);
        wall.push_back(std::move(k));
    }
    for (int i = 8; i <= 19; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL2_IMAGE_PATH);
        k->setPosition(16 * 72, 16 * i);
        wall.push_back(std::move(k));
    }
}
bool Wall::checkCollisionWithWall(int head_x, int head_y)
{
    for (int i = 0; i < wall.size(); i++)
    {
        if (wall[i]->getPosition().first == head_x && wall[i]->getPosition().second == head_y)
        {
            return true;
        }
    }
    return false;
}
void Wall::draw()
{
    for (const auto &i : wall)
    {
        i->draw();
    }
}
