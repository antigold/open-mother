#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "window.h"
#include "game.h"
#include "vector"
#include "filesys.h"
#include "audio.h"
#include "logging.h"

class MapTile {
private:
    SDL_FRect tile;
    GameVector pos;
    SDL_Texture* texture;

public:
    bool top_col;
    bool bot_col;
    bool left_col;
    bool right_col;
    GameVector corners[4] = {GameVector(0,0),GameVector(0,0),GameVector(0,0),GameVector(0,0)};
    MapTile(float xpos, float ypos, SDL_Texture* texture) // TODO soon add collision
        : pos(xpos, ypos), texture(texture) {
            aabb();
        }
    void render(SDL_Renderer* renderer);
    void aabb();
};

struct MapData{
    std::string mapname;
    std::string musicpath;
    std::string musicname;
    std::string musicauthor;

    std::vector<MapTile> tiles;
};

// extern std::vector<MapTile> tiles; //map tiles will be stored here
extern MapData map; // whole mapdata here

void load_map(const char* filepath);
void unload_map();