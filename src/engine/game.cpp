// OPEN-MOTHER GAME CODE
//
// "run_game_loop()","update_game_state()",etc...
// player = { 300.0f, 200.0f, 32.0f, 32.0f } i need this for later

#include "game.h"

// * MAP TILE
// TODO - make this class a bit better cuz now it's kinda dogshit
// all tiles will be 40x40 px
MapTile::MapTile(int xpos, int ypos, int r, int g, int b) {
    tile.x = xpos*40;
    tile.y = ypos*40;
    tile.w = 40;
    tile.h = 40;
    this->r = r;
    this->g = g;
    this->b = b;
}

// Render function implementation
void MapTile::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255); //color
    SDL_RenderFillRect(renderer, &this->tile); //draws on screen
}