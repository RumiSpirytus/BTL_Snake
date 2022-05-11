#pragma once

#include <bits/stdc++.h>
using namespace std;
// Using SDL, SDL_image, standard IO, and strings

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Texture.hpp"
#include "Snake.hpp"

class Game
{
private:
    bool isRunning = true;
    SDL_Window *gWindow = NULL;
    LTexture l;
    Snake s;

public:
    Game();
    ~Game();

    bool init();
    bool loadMedia();

    void handleEvents();
    void update();
    void render();
    void clear()
    {
        SDL_RenderClear(gRenderer);
    }
    void close();

    bool getGameState() { return isRunning; }

    static SDL_Renderer *gRenderer;
};
