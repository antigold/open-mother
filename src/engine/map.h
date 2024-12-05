#pragma once

#include <SDL2/SDL.h>
#include "window.h"
#include "game.h"

class MapTile {
private:
    SDL_FRect tile;
    GameVector pos;
    int r, g, b;

public:
    MapTile(float xpos, float ypos, int r, int g, int b)
        : pos(xpos, ypos), r(r), g(g), b(b) {}
    void render(SDL_Renderer* renderer);
};
