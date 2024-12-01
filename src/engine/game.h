#include <SDL2/SDL.h>
#include "window.h"

class MapTile {
private:
    SDL_Rect tile;
    int r, g, b;

public:
    MapTile(int xpos, int ypos, int xsize, int ysize, int r, int g, int b);
    void render(SDL_Renderer* renderer);
};
