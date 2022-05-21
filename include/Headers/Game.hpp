#pragma once
#include "Menu.hpp"
#include <bits/stdc++.h>
using namespace std;
// Using SDL, SDL_image, standard IO, and strings

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Snake.hpp"
#include "Object.hpp"
class Game
{
private:
    bool isRunning = true;
    SDL_Window *gWindow = NULL;
    Object background;
    Snake s;
    LTexture gTextTexture;
    int score;
    bool isDead;
    Object gameover;
    Menu me;

public:
    Game();
    ~Game();

    bool init();
    bool loadMedia();
    void gameOver();
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
    static TTF_Font *gFont;
    static bool isDead;
};
