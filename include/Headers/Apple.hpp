#include "Object.hpp"

class Apple
{
private:
    Object apple;
    std::pair<int, int> pos;

public:
    Apple();
    ~Apple();
    void draw();
    void genarateApple();
    void loadMedia();
    std::pair<int, int> getApple()
    {
        return pos;
    }
};