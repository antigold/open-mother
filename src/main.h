#pragma once
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
#include "engine/input.h"
//i should make main.h bruh
#include "engine/console.h"
#include <vector>
#include <iostream> // to debug
#include <pthread.h>
#include <unistd.h>
//fuck you git

extern bool running;