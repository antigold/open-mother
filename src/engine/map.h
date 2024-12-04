#include <SDL2/SDL.h>
#include "window.h"

class MapTile {
private:
    SDL_FRect tile;
    int r, g, b;

public:
    MapTile(int xpos, int ypos, int r, int g, int b);
    void render(SDL_Renderer* renderer);
};
