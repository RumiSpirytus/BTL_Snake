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
    for (int i = 0; i <= 60; i++)
    {
        std::unique_ptr<Object> k = std::make_unique<Object>();
        k->loadMedia(WALL_IMAGE_PATH);
        k->setPosition(16 * i, 16 * 16);
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