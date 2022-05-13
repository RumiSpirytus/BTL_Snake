#include "Object.hpp"

Object::Object()
{
    clip = {0, 0, 16, 16};
    pos = std::make_pair(0, 0);
}
Object::~Object()
{
    //
}
void Object::loadMedia(std::string path)
{
    ob_texture.loadFromFile(path);
}
