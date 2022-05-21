#include "Game.hpp"
#include "Defs.hpp"
SDL_Renderer *Game::gRenderer = nullptr;
TTF_Font *Game::gFont = nullptr;
Game::Game()
{
    bool isDead = false;
    score = 0;
}
Game::~Game() {}

bool Game::init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow("Nguyen Duc Thien 21020407", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(
                gWindow, -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n",
                       SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf(
                        "SDL_image could not initialize! SDL_image Error: %s\n",
                        IMG_GetError());
                    success = false;
                }

                // Initialize SDL_ttf
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
                           TTF_GetError());
                }
            }
        }
    }
    return success;
}

bool Game::loadMedia()
{
    bool success = true;
    background.loadMedia(BACKGROUND_PATH);
    background.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gameover.loadMedia(GAMEOVER_IMAGE_PATH);
    gameover.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    s.Loadmedia();
    gFont = TTF_OpenFont("./Images/Caviar_Dreams_Bold.ttf", 28);
    // me.LoadMenu();
    return success;
}

void Game::handleEvents()
{
    // Event handler
    SDL_Event e;
    // Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        // User requests quit
        if (e.type == SDL_QUIT)
        {
            isRunning = false;
        }
        /*else if (me.MenuState())
        {
            me.MenuHandleEvent(e, isRunning);
        }*/
        s.HandleInputAction(e);
    }
}
void Game::update()
{
    s.Update(score, isDead);
}

void Game::render()
{
    SDL_RenderClear(gRenderer);
    if (!isDead)
    {
        background.draw();
        s.DrawSnake();
        // Render text
        SDL_Color textColor = {0, 0, 0};
        gTextTexture.loadFromRenderText("Score: " + to_string(score), textColor);
        gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
        // me.MenuRender();
    }
    else
    {
        gameover.draw();
    }
    SDL_RenderPresent(gRenderer);
}

void Game::close()
{
    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    // Free the sound effects
    gWindow = NULL;
    gRenderer = NULL;
    SDL_Quit();
    cout << "Game clear";
}
