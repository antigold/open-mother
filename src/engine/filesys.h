#include <string>
#include <filesystem>
#include "mod.h"
#include <fstream>
#include <vector>
#include "logging.h"

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#include <limits.h>
#endif

std::string get_exe_path(); // gets the executable's path

const char* get_relative_path(const std::string& relativePath); // gets the path of things inside mod
/*
! modname <- STARTS HERE
! ├── maps
! │   └── ...
! ├── music
! │   └── ...
! └── textures
!     └── ...
! 
! if i want to grab the path of the pinkie.jpg texture, i do "get_relative_path("textures/pinkie.jpg")"
*/

bool is_map_valid(const char* path);