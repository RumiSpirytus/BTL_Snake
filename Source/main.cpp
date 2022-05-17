#include "Game.hpp"

Game *game = NULL;

int main(int argc, char *args[])
{

    game = new Game();
    if (!game->init())
    {
        cout << "Failed to init window" << endl;
    }
    else
    {
        if (!game->loadMedia())
        {
            cout << "Failed to load Media" << endl;
        }
        else
        {
            while (game->getGameState())
            {
                game->clear();
                game->handleEvents();
                game->update();
                game->render();
                SDL_Delay(50);
            }
        }
    }
    game->close();
    return 0;
}