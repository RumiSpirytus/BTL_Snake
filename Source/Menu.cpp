#include <Menu.hpp>

Menu::Menu()
{
    inMenu = true;
    mousep = std::make_pair(0, 0);
}

Menu::~Menu()
{
}

void Menu::LoadMenu()
{
    menuBackground.loadMedia(MENU_IMAGE_PATH);
    menuBackground.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Menu::MenuRender()
{
}
bool Menu::MenuState()
{
    return inMenu;
}

void MenuHanddleEvent(SDL_Event &e, bool &running)
{
}