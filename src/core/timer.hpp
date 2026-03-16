#pragma once
#include <deque>
#include <SDL3/SDL.h>

class Timer
{
public:
    Timer();
    ~Timer();

    double update_timer();
    int get_current_fps();

    double get_dt();

private:
    std::deque<double> frame_times;

    int COUNTER_FREQUENCY = 0;
    double dt = 0;

    Uint64 last_time = 0;
};