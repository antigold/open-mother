// OPEN-MOTHER PLAYER CODE
//
// player stuff, you know.
#include "player.h"
#include "timer.h"
#include "input.h"
#include "game.h"

SDL_FRect player;

void init_player(){
    player = { 300.0f, 200.0f, 32.0f, 32.0f };
}

void player_move(){
    if (is_key_pressed(SDL_SCANCODE_W)) camera.sety(camera.gety() - (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_S)) camera.sety(camera.gety() + (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_A)) camera.setx(camera.getx() - (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_D)) camera.setx(camera.getx() + (speed * dt));
}