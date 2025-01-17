#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstdio>
#include <string>

bool init_audio();
bool play_music(const char* musicpath);
void stop_audio();