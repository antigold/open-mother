#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "engine/window.h"
#include "engine/player.h"

int main() {
    Uint32 lastTime = SDL_GetTicks(); //gets initial time
    bool running = true;
    SDL_Event event;

    SDL_FRect player = { 300.0f, 200.0f, 32.0f, 32.0f };

    initialize_sdl();
    while (running) {
        Uint32 currentTime = SDL_GetTicks();  //gets current time
        float dt = (currentTime - lastTime) / 1000.0f;  //calculates delta time
        lastTime = currentTime;  //updates lasttime

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        
        const Uint8* keys = SDL_GetKeyboardState(NULL);
        // printf("W: %d, A: %d, S: %d, D: %d\n", keys[SDL_SCANCODE_W], keys[SDL_SCANCODE_A], keys[SDL_SCANCODE_S], keys[SDL_SCANCODE_D]);
        printf("X: %f, Y: %f\n", player.y, player.x);
        printf("delta time = %f", dt);
        if (keys[SDL_SCANCODE_W]) player.y -= speed * dt;
        if (keys[SDL_SCANCODE_S]) player.y += speed * dt;
        if (keys[SDL_SCANCODE_A]) player.x -= speed * dt;
        if (keys[SDL_SCANCODE_D]) player.x += speed * dt;

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