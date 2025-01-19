#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>
#include <functional> // for functions?
#include "map.h"
#include "renderer.h"
#include "main.h"
#include "logging.h"

void console_init();
void* listen_for_commands(void* arg);