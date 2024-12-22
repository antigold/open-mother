#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "window.h"
#include "game.h"
#include "vector"

class MapTile {
private:
    SDL_FRect tile;
    GameVector pos;
    SDL_Texture* texture;

public:
    MapTile(float xpos, float ypos, SDL_Texture* texture)
        : pos(xpos, ypos), texture(texture) {}
    void render(SDL_Renderer* renderer);
};

struct MapData{
    std::string mapname;
    std::string musicpath;
    std::string musicname;
    std::string musicauthor;

    std::vector<MapTile> tiles;
};

void load_map();

// extern std::vector<MapTile> tiles; //map tiles will be stored here
extern MapData map; // whole mapdata here