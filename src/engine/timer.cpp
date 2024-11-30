// OPEN-MOTHER TIMER CODE
//
// delta time and all that
#include "timer.h"

Uint32 lastTime;
float dt;

void init_time(){
    lastTime = SDL_GetTicks(); //gets initial time
}

void calculate_dt(){
    Uint32 currentTime = SDL_GetTicks();  //gets current time
    dt = (currentTime - lastTime) / 1000.0f;  //calculates delta time
    lastTime = currentTime;  //updates lasttime
}