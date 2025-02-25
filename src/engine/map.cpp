// OPEN-MOTHER MAP CODE
//
// "load_map()","render_map()","handle_collisions()","update_map()"

//for now we will hardcode a map inside here, then we will use .omm files

#include "map.h"
#include "audio.h"
#include "filesys.h"

int tilesize = 80;

MapData map;
// * MAP TILE
// TODO - make this class a bit better cuz now it's kinda bad
// all tiles will be 40x40 px
// MapTile::MapTile(float xpos, float ypos, int r, int g, int b) {
//     tile.x = xpos*40;
//     tile.y = ypos*40;
//     tile.w = 40.0;
//     tile.h = 40.0;
//     this->r = r;
//     this->g = g;
//     this->b = b;
// }

// Render function implementation
void MapTile::render(SDL_Renderer* renderer) {
    SDL_FRect renderTile = {
        pos.getrelativex() + (pos.getx() * (tilesize - 1)), // why the fuck does it work when i subtract 1
        pos.getrelativey() + (pos.gety() * (tilesize - 1)), // otherwise leaves gaps
        tilesize,
        tilesize
    };

    // printf("%f - %f\n", pos.getx(), pos.gety());
    // SDL_SetRenderDrawColor(renderer, r, g, b, 255); //color
    // SDL_RenderFillRectF(renderer, &renderTile); //draws on screen
    SDL_RenderCopyF(renderer, texture, nullptr, &renderTile);
}

// TODO optimize
// get tile AABB
void MapTile::aabb(){
    // put(INFO_CODE,"sartek");
    corners[0] = GameVector(pos.getx()*tilesize, pos.gety()*tilesize);
    corners[1] = GameVector((pos.getx()*tilesize)+tilesize, pos.gety()*tilesize);
    corners[2] = GameVector(pos.getx()*tilesize, (pos.gety()*tilesize)+tilesize);
    corners[3] = GameVector((pos.getx()*tilesize)+tilesize, (pos.gety()*tilesize)+tilesize);
    // std::cout << corners[0].getx();
}

// std::vector<MapTile> tiles; // declare

void load_map(const char* filepath){
    readomm(filepath);
    play_music(get_relative_path(map.musicpath));
}

void unload_map(){
    map.tiles.clear();
}
