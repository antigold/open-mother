// i don't fw filesystems
#include "filesys.h"
#include "logging.h"
#include "../../external/json/single_include/nlohmann/json.hpp"

std::string get_exe_path() {
    char buffer[4096];
#if defined(_WIN32)
    GetModuleFileNameA(nullptr, buffer, sizeof(buffer));
#elif defined(__linux__)
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
    }
#else
    throw std::runtime_error("Unsupported platform");
#endif
    return std::string(buffer);
}

const char* get_relative_path(const std::string& relativePath) {
    static std::string fullpath;
    std::filesystem::path executablePath = get_exe_path();
    std::filesystem::path executableDir = executablePath.parent_path();
    fullpath = (executableDir / modname / relativePath).string();
    return fullpath.c_str();
}

std::vector<unsigned char> omm_magic_header = {0x6F, 0x6D, 0x6D};

//!
//! MAP STUFF
//!

bool is_map_valid(const char* path){ //checks if map has that magic header thing
    std::ifstream file(get_relative_path(path), std::ios::binary);
    std::vector<unsigned char> header(omm_magic_header.size());
    file.read(reinterpret_cast<char*>(header.data()), omm_magic_header.size());

    if (header == omm_magic_header) {
        // printf("valid omm file");
        put(INFO_CODE, "valid omm file");
        return true;
    } else {
        // printf("engk engk");
        put(ERROR_CODE,"invalid omm file");
        return false;
    }
}
