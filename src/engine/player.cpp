// OPEN-MOTHER PLAYER CODE
//
// player stuff, you know.
#include "player.h"
#include "timer.h"
#include "input.h"

SDL_FRect player;

void init_player(){
    player = { 300.0f, 200.0f, 32.0f, 32.0f };
}

void player_move(){
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (is_key_pressed(SDL_SCANCODE_W)) player.y -= speed * dt;
    if (is_key_pressed(SDL_SCANCODE_S)) player.y += speed * dt;
    if (is_key_pressed(SDL_SCANCODE_A)) player.x -= speed * dt;
    if (is_key_pressed(SDL_SCANCODE_D)) player.x += speed * dt;
}