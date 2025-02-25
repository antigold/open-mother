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
    init_sdl(); //SDL
    get_window_resolution(); //gets initial window resolution
    init_time(); //delta time
    fetch_mod_textures(); //gets all textures from mod/textures
    init_player(); // player -> soon will become lua
    init_audio(); // SDL mixer
    init_lua(); // initializes lua state
    init_console(); // starting console and gets concommands from lua files

    load_map("maps/map.omm"); //loads map (remove soon)

    pthread_t consolethread; //another thread for console so both run at the same time
    pthread_create(&consolethread, NULL, listen_for_commands, NULL);

    // map.tiles.emplace_back(MapTile(0,0,get_texture("swag")));

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
            init_console();
        }
    
        SDL_Delay(6);//do this or else the movement won't work?
    }
    pthread_join(consolethread, NULL);

    stop_audio();
    exit_sdl();
    
    return 0;
}

// ! QADTDL
// TODO - fix logs, make std::cout, printf and put more consistent
// TODO - fix console stuff
// TODO - fix map addtile
// TODO - almost done, now assets per mod, include main lua files and maps
// TODO - start working on entities
// TODO - zoom in (add + zoompixel to relative distance and tiles += zoomdistance pixels?)