#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include <functional> // for functions?
#include <cstring>
#include "audio.h"
#include "map.h"
#include "renderer.h"
#include "main.h"
#include "logging.h"
#include "lua/lua.h"

void init_console();
void* listen_for_commands(void* arg);