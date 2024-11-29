#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "engine/window.h"
#include "engine/player.h"
#include "engine/timer.h"

int main() {
    Uint32 lastTime = SDL_GetTicks(); //gets initial time
    bool running = true;
    SDL_Event event;

    //initializes stuff
    init_time();
    init_sdl();
    init_player();

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        
        // V debug stuff
        // printf("W: %d, A: %d, S: %d, D: %d\n", keys[SDL_SCANCODE_W], keys[SDL_SCANCODE_A], keys[SDL_SCANCODE_S], keys[SDL_SCANCODE_D]);
        // printf("X: %f, Y: %f\n", player.y, player.x);
        printf("delta time = %f", get_dt());
        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRectF(renderer, &player);

        SDL_RenderPresent(renderer);
        SDL_Delay(8);
    }
    exit_sdl();
    
    return 0;
}