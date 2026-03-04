#include "core/game.hpp"
#include <cstdio>

Game::Game()
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("Error initlizing SDL: %s", SDL_GetError());
    }

    if(!SDL_CreateWindowAndRenderer("Evonic", 1200, 800, SDL_WINDOW_OPENGL, &window, &renderer))
    {
        printf("Failed to create Window and or Renderer: %s", SDL_GetError());
    }

    running = true;
}

Game::~Game()
{
}

void Game::run()
{
    while(running)
    {
        timer.update_timer();
        handle_events();
        update();
        render();
    }
}

void Game::handle_events()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_EVENT_QUIT)
        {
            running = false;
        }
    }
}

void Game::update()
{
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 10, 10, 50, 255);
    SDL_RenderClear(renderer);


    SDL_RenderPresent(renderer);
}