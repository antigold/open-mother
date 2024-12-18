#include "mod.h"

std::string modname;
// TODO - check if the mod is valid or not, using something like a liblist.gam
bool fetch_mod_data(char *mn){
    put(INFO_CODE, "loading mod");
    put(INFO_CODE,mn);
    
    std::string mns(mn);
    modname = mns;

    return true;
}