#define SDL_MAIN_HANDLED //otherwise winblows can't understand this file
#include "main.h"

GameCamera camera = GameCamera(GameVector(0,0));
bool running = true;

int main(int argc, char *argv[]) {
    running = true;
    SDL_Event event;

    printf("OPEN-MOTHER - This engine is heavily unfinished, if you managed to compile it, congratulations\n");

    // checks if it has a mod in arguments, if not, then commits suicide
    if(argc < 2){
        put(ERROR_CODE, "open-mother is a game engine, it needs a mod to run, check if your mod has a x file inside it"); //x is placeholder for liblist.gam for now
        return 0;
    }

    fetch_mod_data(argv[1]);

    //initializes stuff
    init_sdl();
    get_window_resolution();
    init_time();
    init_player();
    init_audio();
    console_init();
    // play_music("src/assets/music/somemusic.ogg");

    // TODO
    // add_texture("test", get_relative_path("textures/pinkie.jpg"), renderer);
    // add_texture("swag", get_relative_path("textures/swag.jpg"), renderer);
    // add_texture("missing", get_relative_path("textures/missing.jpg"), renderer);

    fetch_mod_textures();

    // readomm("maps/map.omm"); // loads map
    load_map("maps/map.omm");

    pthread_t consolethread;
    pthread_create(&consolethread, NULL, listen_for_commands, NULL);

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                pthread_cancel(consolethread);
            }

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
        player_move(); // TODO transform this in lua
        camera.setpos(playerpos);
        for (auto& tile : map.tiles) { // renders map tiles, temporary
            tile.render(renderer);
        }
        player_render();
        render_show();
        render_clear();

        if(is_key_pressed(SDL_SCANCODE_P)){
            console_init();
        }
    
        SDL_Delay(6);//do this or else the movement won't work?
    }
    pthread_join(consolethread, NULL);

    stop_audio();
    exit_sdl();
    
    return 0;
}

// ! QADTDL

// TODO - missing.jpg will be special
// TODO -- almost done, now assets per mod, include main lua files and maps
// TODO - start working on entities
// ! TODO - CONSOLE