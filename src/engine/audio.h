#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstdio>

bool init_audio();
bool play_music(char* musicpath);
void stop_audio();