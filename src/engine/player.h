#pragma once
#include <SDL2/SDL.h>
#include "game.h"
const int speed = 200;
// extern SDL_FRect player; // player square, change this to an object soon
extern GameVector playerpos;

void init_player();
void player_render();
void player_move();