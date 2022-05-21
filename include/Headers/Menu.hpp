#pragma once
#include "Object.hpp"
#include "Defs.hpp"
#include <vector>
class Menu
{
private:
    // Background image
    Object menuBackground;

    // Menu state
    bool inMenu;
    enum
    {
        NewGame,
        HighScore,
        Exit
    };
    LTexture Button[3];
    std::string NameButton[3] = {"New Game", "High Score", "Exit"};
    std::vector<std::pair<int, int>> positem;

    bool Clicked[3] = {0};

    std::pair<int, int> mousep;

public:
    Menu();
    ~Menu();

    void LoadMenu();
    void MenuHandleEvent(SDL_Event &e, bool &isRunning);
    void MenuRender();
    int ButtonFunction(bool Clicked[3]);

    bool MenuState();
};