#include <SDL2/SDL.h>
#include "engine/window.h"
#include "engine/player.h"
#include "engine/timer.h"
#include "engine/input.h"
#include "engine/renderer.h"
#include "engine/audio.h"
#include "engine/game.h"
#include <vector>

int main() {
    bool running = true;
    SDL_Event event;

    //initializes stuff
    init_sdl();
    init_time();
    init_player();
    init_audio();
    // play_music("src/assets/music/somemusic.ogg");

    // TODO - make this happen in map.cpp
    std::vector<MapTile> tiles = {
        MapTile(0, 0, 255, 0, 0), // red
        MapTile(1, 0, 0, 255, 0), // gree
        MapTile(2, 0, 0, 0, 255)  // blue
    };

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }
        // printf("X: %f, Y: %f\n", player.y, player.x);
        calculate_dt();
        player_move();
        for (auto& tile : tiles) { // renders map tiles, temporary
            tile.render(renderer);
        }
        render_pipeline();
        render_show();
        render_clear();
    
        SDL_Delay(6);//do this or else the movement won't work?
    }
    stop_audio();
    exit_sdl();
    
    return 0;
}