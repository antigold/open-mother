#define SDL_MAIN_HANDLED //otherwise winblows can't understand this file
#include <SDL2/SDL.h>
#include "engine/window.h"
#include "engine/player.h"
#include "engine/timer.h"
#include "engine/renderer.h"
#include "engine/audio.h"
#include "engine/game.h"
#include "engine/map.h"
#include "engine/mod.h"
#include "engine/logging.h"
#include "engine/filesys.h"
//i should make main.h bruh
#include <vector>
// #include <iostream> // to debug
//fuck you git

GameCamera camera = GameCamera(GameVector(0,0));

int main(int argc, char *argv[]) {
    bool running = true;
    SDL_Event event;

    put(INFO_CODE, "open mother early access");

    // checks if it has a mod in arguments, if not, then commits suicide
    if(argc < 2){
        put(ERROR_CODE, "undefined mod");
        return 0;
    }

    fetch_mod_data(argv[1]);

    //initializes stuff
    init_sdl();
    get_window_resolution();
    init_time();
    init_player();
    init_audio();
    // play_music("src/assets/music/somemusic.ogg");
    add_texture("test", get_relative_path("textures/pinkie.jpg"), renderer);
    load_map();

    is_map_valid("maps/broken.omm");
    is_map_valid("maps/dev.omm");

    // TODO - make this happen in map.cpp
    // std::vector<MapTile> tiles = {
    //     MapTile(3, 4, get_texture("test")),
    //     MapTile(4, 4, get_texture("test")),
    //     MapTile(5, 4, get_texture("test")),
    //     MapTile(6, 4, get_texture("test")),
    //     MapTile(7, 4, get_texture("test")),
    //     MapTile(17, 4, get_texture("test")),
    // };

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
// DONE - fix the fullscreen thing
// DONE - i put the player in the middle, all i need to do now is to add SCRW/2 to every tile's X and SRCH/2 to every tile's Y
// DONE - TODO - import textures
// DONE - just for tiles for now
// TODO - start working on maps!
// maybe i should try importing a handmade map first.
// TODO - start making mods instead of hardcoding the shit in here
// TODO -- almost done, now assets per mod, include main lua files and maps
// TODO - start working on entities