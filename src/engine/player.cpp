// OPEN-MOTHER PLAYER CODE
//
// player stuff, you know.
#include "player.h"
#include "timer.h"
#include "input.h"
#include "window.h"
#include <SDL2/SDL_rect.h>
int speed = 0.0;
SDL_FRect player;
GameVector playerpos(0,0);

void init_player(){
    speed = 200;
    player = { -16.0f+(windowWidth/2), 16.0f+(windowHeight/2), 32.0f, 32.0f };
}

void player_render(){
    player.x = -16.0f+(windowWidth/2); //centered
    player.y = -16.0f+(windowHeight/2); //centered
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //color
    SDL_RenderFillRectF(renderer, &player); //draws on screen
}

void player_move(){
    if (is_key_pressed(SDL_SCANCODE_W)) playerpos.sety(playerpos.gety() - (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_S)) playerpos.sety(playerpos.gety() + (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_A)) playerpos.setx(playerpos.getx() - (speed * dt));
    if (is_key_pressed(SDL_SCANCODE_D)) playerpos.setx(playerpos.getx() + (speed * dt));
}