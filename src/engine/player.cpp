// OPEN-MOTHER PLAYER CODE
//
// player stuff, you know.
#include "player.h"
#include "timer.h"

SDL_FRect player;

void init_player(){
    player = { 300.0f, 200.0f, 32.0f, 32.0f };
}

void player_input(){
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_W]) player.y -= speed * dt;
    if (keys[SDL_SCANCODE_S]) player.y += speed * dt;
    if (keys[SDL_SCANCODE_A]) player.x -= speed * dt;
    if (keys[SDL_SCANCODE_D]) player.x += speed * dt;
}