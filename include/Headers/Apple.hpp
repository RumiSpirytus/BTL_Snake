#pragma once
#include <bits/stdc++.h>
using namespace std;
// Using SDL, SDL_image, standard IO, and strings

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Texture.hpp"
#include "Snake.hpp"

class Apple()
{

public:
    Apple();
    ~Apple();

    bool init();
    bool loadMedia();
};