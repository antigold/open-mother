// i don't fw filesystems
#include "filesys.h"
#include "game.h"
#include "logging.h"
#include "map.h"

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

//reads a string
//startfile=0 -> reads magic
std::string read_string(std::string filepath, uint startfile) {
    std::ifstream binfile;
    std::string returnstring;
    binfile.open(get_relative_path(filepath), std::ios::binary);

    binfile.seekg(startfile, std::ios::cur);

    if (!binfile) {
        put(ERROR_CODE,"thats not a file!");
        return "";
    }

    //reads first byte (string length)
    char byte;
    binfile.read(&byte, 1);

    if (binfile.gcount() != 1) {
        put(ERROR_CODE, "error reading initial byte");
        return "";
    }

    //convert
    unsigned int strlength = static_cast<unsigned char>(byte);
    // printf("%u",strlength); // ! prints length normally

    //read the strlength amt of bytes starting from arg
    std::vector<char> decstr(strlength);
    binfile.read(decstr.data(), strlength);
    if (binfile.gcount() != strlength) {
        put(ERROR_CODE, "there was an error reading the bytes for \"\033[1;39m\033[1;34m" + filepath + "\033[0m\"");
        return "";
    }

    for (char byte : decstr) {
        // printf("%c",byte);
        // put(WARN_CODE, "adding data to string");
        returnstring += byte;
    }
    return returnstring;
}

int read_int(std::string filepath, uint& startfile) {
    std::ifstream binfile;
    int returnint = 0;

    binfile.open(get_relative_path(filepath), std::ios::binary);

    binfile.seekg(startfile, std::ios::cur);

    if (!binfile) {
        put(ERROR_CODE,"thats not a file!");
        return 0;
    }

    //reads first byte (number length (00))
    char byte;
    binfile.read(&byte, 1);

    if (binfile.gcount() != 1) {
        put(ERROR_CODE, "error reading initial byte");
        return 0;
    }

    //convert
    unsigned int intlength = static_cast<unsigned char>(byte);
    // printf("%i",intlength); // ! prints length normally

    std::vector<char> buffer(intlength);
    binfile.read(buffer.data(), intlength);
    if (binfile.gcount() != static_cast<std::streamsize>(intlength)) {
        put(ERROR_CODE, "there was an error reading the bytes for \"\033[1;39m\033[1;34m" + filepath + "\033[0m\"");
        return 0;
    }

    startfile += intlength + 1;
    // printf("startfile is %i\n",startfile);

    //converts
    for (unsigned int i = 0; i < intlength; ++i) {
        returnint = (returnint << 8) | (static_cast<unsigned char>(buffer[i]));
    }
    return returnint;
}

//!
//! MAP STUFF
//!

void readomm(std::string filepath){
    std::string magic = "omm";
    if(read_string(filepath, 0) != magic){
        put(ERROR_CODE, "Can't read map file, no magic header detected");
        return;
    }

    uint32_t locationinmetadata = 4; //this value determines WHERE in the bin file you are
    std::string tempstr;
    std::vector<std::string> metadata;

    for(int i = 0; i < 4; i++) { // four times since 4 strings in metadata.
        tempstr = read_string(filepath, locationinmetadata);
        // put(INFO_CODE, tempstr);
        locationinmetadata += tempstr.length()+1;
        metadata.emplace_back(tempstr);
        // printf("%d",locationinmetadata);
    }

    map.mapname = metadata[0];
    map.musicpath = metadata[1];
    map.musicname = metadata[2];
    map.musicauthor = metadata[3];

    put(INFO_CODE, "loading map " + filepath + " - " + map.mapname + "...");

    // put(INFO_CODE, "map name : " + metadata[0]);
    // put(INFO_CODE, "music path : " + metadata[1]);
    // put(INFO_CODE, "music name : " + metadata[2]);
    // put(INFO_CODE, "music author name : " + metadata[3]);

    // locationinmetadata stays the same, not at 0;
    // gets how many tiles in map 
    // ! write this down in privatewiki the fact that it needs to know how many tiles beforehand
    

    int tilenumber = read_int(filepath, locationinmetadata); // amount of tiles inside map, use this so i can know where to stop

    // gets tile data
    for(int i = 0; i < tilenumber; i++){
        int temptilex = read_int(filepath, locationinmetadata); //gets x from file
        int temptiley = read_int(filepath, locationinmetadata); //gets y from file
        
        std::string tiletexture = read_string(filepath, locationinmetadata); // gets texture name

        locationinmetadata += tiletexture.length()+1; // increments

        // printf("SUMMONING TILE AT (%i; %i)\n",temptilex,temptiley);
        map.tiles.emplace_back(MapTile(temptilex,temptiley,get_texture(tiletexture))); //add tiles read before to map
    }
}

// TODO - fix read_string to make it increment locationinmetadata