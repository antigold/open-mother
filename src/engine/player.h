#pragma once
#include <SDL2/SDL.h>
#include "game.h"
extern int speed;
// extern SDL_FRect player; // player square, change this to an object soon
extern GameVector playerpos;

void init_player();
void player_render();
void player_move();

// TODO - make this an object