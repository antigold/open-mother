// OPEN-MOTHER PLAYER CODE
//
// player stuff, you know.
#include "player.h"
#include "timer.h"

void init_player(){
    SDL_FRect player = { 300.0f, 200.0f, 32.0f, 32.0f };
}

void player_input(){
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_W]) player.y -= speed * get_dt();
    if (keys[SDL_SCANCODE_S]) player.y += speed * get_dt();
    if (keys[SDL_SCANCODE_A]) player.x -= speed * get_dt();
    if (keys[SDL_SCANCODE_D]) player.x += speed * get_dt();
}