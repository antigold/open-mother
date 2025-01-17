#include "mod.h"
#include "filesys.h"
#include "game.h"
#include "logging.h"
#include <filesystem>

std::string modname;
// TODO - check if the mod is valid or not, using something like a liblist.gam
bool fetch_mod_data(char *mn){
    
    std::string mns(mn);
    modname = mns;

    put(INFO_CODE, "loading mod : " + modname);
    return true;
}

//worst implementation of this ever, you better run this game with 64GB of ram otherwise it won't run lmao
// TODO make this shit work better, cuz it WILL import a mp4 if it's in there or smth
bool fetch_mod_textures(){
    std::string texturespath = get_relative_path("textures");
    for(const auto & entry : std::filesystem::directory_iterator(texturespath)){ //every entry in this
        std::string tempentry = entry.path().filename().string(); //lol wtf
        // put(INFO_CODE, "FOUND TEXTURE : " + tempentry);// debug

        std::string texturepath = get_relative_path("textures/" + tempentry); // gets full path to texture
        std::string texturename = tempentry.erase(tempentry.length() - 4); // gets texture name minus the extension (always 4 chars, unless you use .tiff or whatever)

        add_texture(texturename.c_str(), texturepath.c_str(), renderer); // doesn't this eat a lot of memory?
    }
    return true;
}