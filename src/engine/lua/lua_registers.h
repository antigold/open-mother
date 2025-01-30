#pragma once
#include <lua.hpp>
#include <iostream>
#include <string>
#include <future>
#include <thread>
#include "../logging.h"
#include "../player.h"
#include "../timer.h"
#include "../map.h"
#include "../renderer.h"
#include "../game.h"
#include "../filesys.h"

#include "lua.h"

void lua_initregisters();