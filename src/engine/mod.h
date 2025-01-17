#pragma once
#include <string>
#include "logging.h"
#include <filesystem>
#include "filesys.h"
#include "game.h"

extern std::string modname;

bool fetch_mod_data(char *mn);

bool fetch_mod_textures();