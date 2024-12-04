#include <SDL2/SDL.h>
#include "engine/window.h"
#include "engine/player.h"
#include "engine/timer.h"
#include "engine/input.h"
#include "engine/renderer.h"
#include "engine/audio.h"
#include "engine/game.h"
#include "engine/map.h"
#include <vector>

GameCamera camera = GameCamera(GameVector(0,0));

int main() {
    bool running = true;
    SDL_Event event;

    camera.debug();
    //initializes stuff
    init_sdl();
    init_time();
    init_player();
    init_audio();
    // play_music("src/assets/music/somemusic.ogg");

    // TODO - make this happen in map.cpp
    std::vector<MapTile> tiles = {
        MapTile(3, 4, 255, 0, 0), // red
        MapTile(4, 4, 0, 255, 0), // gree
        MapTile(5, 4, 0, 0, 255),  // blue
        MapTile(6, 4, 0, 0, 255), // blue
        MapTile(7, 4, 0, 0, 255),  // blue
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