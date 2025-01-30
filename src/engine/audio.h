#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <thread>

bool init_audio();
bool play_music(const char* musicpath);
void play_sound(const char* soundpath);
void stop_audio();