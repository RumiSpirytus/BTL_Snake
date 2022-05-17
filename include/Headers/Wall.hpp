#pragma once
#include "Object.hpp"
#include <vector>
#include <memory>
class Wall
{
private:
    std::vector<std::unique_ptr<Object>> wall;

public:
    Wall();
    ~Wall();
    void loadMedia();
    bool checkCollisionWithWall(int, int);
    void draw();
};