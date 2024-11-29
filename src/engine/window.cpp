// OPEN-MOTHER WINDOW CODE
//
// this code will contain window management stuff like
// "create_window()", "get_window_dimensions()"?, "close_window()"

// TODO comment this code for later

#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

void initialize_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    }
}

void exit_sdl() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    SDL_Quit();
}