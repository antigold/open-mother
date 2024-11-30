#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "engine/window.h"
#include "engine/player.h"
#include "engine/timer.h"
#include "engine/input.h"

int main() {
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
        calculate_dt();
        printf("delta time = %f \n", dt);

        player_move();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRectF(renderer, &player);

        SDL_RenderPresent(renderer);
        SDL_Delay(6);//do this or else the movement won't work?
    }
    exit_sdl();
    
    return 0;
}