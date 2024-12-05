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
    get_window_resolution();
    init_time();
    init_player();
    init_audio();
    play_music("src/assets/music/ost.ogg");

    // TODO - make this happen in map.cpp
    std::vector<MapTile> tiles = {
        MapTile(3, 4, 255, 0, 0), // red
        MapTile(4, 4, 0, 255, 0), // gree
        MapTile(5, 4, 0, 0, 255),  // blue
        MapTile(6, 4, 0, 0, 255), // blue
        MapTile(7, 4, 0, 0, 255),  // blue
        MapTile(17, 4, 0, 255, 0),  // green
    };

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;

            if (event.type == SDL_WINDOWEVENT) {
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_RESIZED:  // Triggered when the window is resized
                    case SDL_WINDOWEVENT_SIZE_CHANGED: {  // Triggered when size is explicitly changed
                        get_window_resolution();
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        // printf("x: %i, y: %i\n", windowWidth, windowHeight);
        // printf("X: %f, Y: %f\n", player.y, player.x);
        calculate_dt();
        player_move();
        camera.setpos(playerpos);
        for (auto& tile : tiles) { // renders map tiles, temporary
            tile.render(renderer);
        }
        player_render();
        render_show();
        render_clear();
    
        SDL_Delay(6);//do this or else the movement won't work?
    }
    stop_audio();
    exit_sdl();
    
    return 0;
}

// ! QADTDL
// TODO - fix the fullscreen thing
// i put the player in the middle, all i need to do now is to add SCRW/2 to every tile's X and SRCH/2 to every tile's Y