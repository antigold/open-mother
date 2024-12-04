// OPEN-MOTHER RENDERER CODE
//
// this file will contain functions to draw sprites, etc
// "draw_sprite()","draw_text()", "draw_tile()" etc...
// probably will add a map renderer first

#include "renderer.h"
#include "window.h"
#include "player.h"
#include "game.h"

// * RENDER PIPELINE : THIS IS WHERE EVERYTHING WILL BE PASSED TO RENDER
void render_pipeline(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // sets color to white
    SDL_RenderFillRectF(renderer, &player); // renders player
}

void render_show(){
    SDL_RenderPresent(renderer); // shows render
}

void render_clear(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // sets color to black
    SDL_RenderClear(renderer); // clears screen, will probably remove soon
}
