#pragma once
#include <SDL2/SDL.h>
#include <cstdio>

extern SDL_Renderer* renderer;
extern SDL_Window* window;

extern float windowWidth;
extern float windowHeight;

void init_sdl();
void exit_sdl();

void get_window_resolution();