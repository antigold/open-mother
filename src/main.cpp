#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "engine/window.h"
#include "engine/player.h"
#include "engine/timer.h"
#include "engine/input.h"
#include "engine/renderer.h"

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
        // printf("X: %f, Y: %f\n", player.y, player.x);
        calculate_dt();
        player_move();
        render_loop();
    
        SDL_Delay(6);//do this or else the movement won't work?
    }
    exit_sdl();
    
    return 0;
}