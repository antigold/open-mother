// OPEN-MOTHER AUDIO CODE
//
// this code will have all the audio stuff, like
// "initialize_audio()","play_music()","play_sound()","stop_music()","pause_music()", etc...
#include "audio.h"
#include "logging.h"
#include "filesys.h"
#include <SDL2/SDL_mixer.h>

Mix_Music* music;

bool init_audio() {
    //initialize SDL audio
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << '\n'; 
        return false;
    }

    //initialize SDL mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        std::cerr << "Error initializing SDL_mixer: " << Mix_GetError() << '\n';
        SDL_Quit();
        return false;
    }
    return true;
}

bool play_music(const char* musicpath){
    //load a music file
    music = Mix_LoadMUS(musicpath);
    if (!music) {
        put(ERROR_CODE, Mix_GetError());
        Mix_CloseAudio();
        return false;
    }

    //play the music and return true
    Mix_PlayMusic(music, -1);
    return true;
}

//for sfx
void play_sound(const char* soundpath) {
    //load it
    Mix_Chunk* sfx = Mix_LoadWAV(get_relative_path(soundpath));
    if (sfx == NULL) {
        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        return;
    }

    //once
    if (Mix_PlayChannel(0, sfx, 0) == -1) {
        printf("Mix_PlayChannel failed! SDL_mixer Error: %s\n", Mix_GetError());
    }

    //freeeeeee it
    // Mix_FreeChunk(sfx);

    //fuck this shit im using cgpt
    std::thread([sfx]() {
        while (Mix_Playing(0)) {
            SDL_Delay(100);  // Delay to avoid busy-waiting
        }
        // Free the sound effect after it's finished playing
        Mix_FreeChunk(sfx);
    }).detach();  // Detach the thread to allow independent execution
}

void stop_audio(){
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}