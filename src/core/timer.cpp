#include "core/timer.hpp"
#include <cstdio>

Timer::Timer()
{
    COUNTER_FREQUENCY = SDL_GetPerformanceFrequency();
    last_time = SDL_GetPerformanceCounter();
}

Timer::~Timer()
{
}

double Timer::update_timer()
{
    Uint64 current_time = SDL_GetPerformanceCounter();
    dt = (current_time - last_time) / static_cast<double>(COUNTER_FREQUENCY);
    last_time = current_time;

    frame_times.emplace_front(dt);

    double total = 0.0;
    for (auto it = frame_times.begin(); it != frame_times.end(); ++it)
    {
        total += *it;
    }

    while (!frame_times.empty() && total > 1.0) {
        total -= frame_times.back();   // subtract the oldest frame
        frame_times.pop_back();        // remove it
    }

    return dt;
}
