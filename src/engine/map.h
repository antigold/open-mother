#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "window.h"
#include "game.h"

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
