#include "Menu.hpp"
#include "Defs.hpp"
#include "Game.hpp"
Menu::Menu()
{
    inMenu = true;
    mousep = std::make_pair(0, 0);
    for (int i = 0; i < 3; i++)
    {
        positem.push_back(std::make_pair(0, 0));
    }
}

Menu::~Menu()
{
}

void Menu::LoadMenu()
{
    menuBackground.loadMedia(MENU_IMAGE_PATH);
    menuBackground.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Color textcolor = {0, 0, 0};
    int distance = 30;
    for (int i = 0; i < 3; i++)
    {
        Button[i].loadFromRenderText(NameButton[i], textcolor);
        positem[i].first = (SCREEN_WIDTH - Button[i].getWidth()) / 2;
        positem[i].second = (SCREEN_HEIGHT - Button[i].getHeight()) / 2;
        if (i > 0)
        {
            positem[i].second += distance;
            distance *= 2;
        }
    }
    cout << positem[2].second << ' ' << positem[1].second;
}

void Menu::MenuRender()
{
    if (inMenu)
    {
        menuBackground.draw();
        for (int i = 0; i < 3; i++)
        {
            Button[i].render(positem[i].first, positem[i].second);
        }
    }
}

bool Menu::MenuState()
{
    return inMenu;
}

void Menu::MenuHandleEvent(SDL_Event &e, bool &Isrunning)
{

    if (inMenu)
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            mousep.first = e.button.x;
            mousep.second = e.button.y;
            cout << mousep.first << ' ' << mousep.second;
            for (int i = 0; i < 3; i++)
            {
                if (mousep.first >= positem[i].first && mousep.second >= positem[i].second && mousep.second <= positem[i].first + Button[i].getWidth() && mousep.second <= positem[i].second + 30 && e.button.button == SDL_BUTTON_LEFT)
                    Clicked[i] = 1;
                if (Clicked[i] == Exit)
                    Isrunning = false;
            }
        }
    }
}

int Menu::ButtonFunction(bool Clicked[3])
{
    if (Clicked[NewGame])
        inMenu = false;
    else if (Clicked[Exit])
        return Exit;
    return 0;
}