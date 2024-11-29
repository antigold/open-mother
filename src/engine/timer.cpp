// OPEN-MOTHER TIMER CODE
//
// delta time and all that
#include "timer.h"

void init_time(){
    lastTime = SDL_GetTicks(); //gets initial time
}

float get_dt(){
        Uint32 currentTime = SDL_GetTicks();  //gets current time
        float dt = (currentTime - lastTime) / 1000.0f;  //calculates delta time
        lastTime = currentTime;  //updates lasttime
        return dt;
}