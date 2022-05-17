#include "Apple.hpp"
#include "Defs.hpp"
Apple::Apple()
{
    pos = std::make_pair(10 * 16, 10 * 16);
}
Apple::~Apple()
{
    //
}
void Apple::loadMedia()
{
    apple.loadMedia(APPLE_IMAGE_PATH);
    apple.setPosition(pos.first, pos.second);
}
void Apple::draw()
{
    apple.draw();
}
void Apple::genarateApple()
{
    pos.first = (rand() % 80) * 16 + 16 * 2;
    pos.second = (rand() % 45) * 16 + 16 * 2;
    apple.setPosition(pos.first, pos.second);
}