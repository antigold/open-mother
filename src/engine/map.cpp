// OPEN-MOTHER MAP CODE
//
// "load_map()","render_map()","handle_collisions()","update_map()"

//for now we will hardcode a map inside here, then we will use .omm files

#include "map.h"

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