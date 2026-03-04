#pragma once
#include <SDL3/SDL.h>
#include "core/timer.hpp"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    bool running = false;

    SDL_Window *window;
    SDL_Renderer *renderer;
    Timer timer;

    void handle_events();
    void update();
    void render();
};