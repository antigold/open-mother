#include "mod.h"

std::string modname;
// TODO - check if the mod is valid or not, using something like a liblist.gam
bool fetch_mod_data(char *mn){
    
    std::string mns(mn);
    modname = mns;

    put(INFO_CODE, "loading mod : " + modname);
    return true;
}