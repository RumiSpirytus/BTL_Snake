#pragma once
#include "Object.hpp"
#include "Defs.hpp"
#
class Menu
{
private:
    // Background image
    Object menuBackground;

    // Menu state
    bool inMenu;

    enum
    {
        NEW_GAME,
        HIGH_SCORE,
        EXIT_GAME,
    };

    std::string Menuoption[3] = {"NEW GAME", "HIGH SCORE", "EXIT GAME"};

    bool IsClicked[3] = {0};

    std::pair<int, int> mousep;

public:
    Menu();
    ~Menu();

    void LoadMenu();
    void MenuHanddleEvent(SDL_Event &e, bool &running);
    void MenuRender();

    bool MenuState();
};