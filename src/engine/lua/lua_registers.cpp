// this is where i will add code that links lua and cpp stuff, such as "set_speed()" etc...

#include "lua_registers.h"

// RENDERING STUFF
int luar_add_tile(lua_State* L) {
    if (lua_gettop(L) != 3) {
        lua_pushstring(L, "Error: Expected 2 integers and 1 string.");
        return 1;
    }

    if (!lua_isnumber(L, 1)) {
        lua_pushstring(L, "Error: First argument must be an integer.");
        return 1;
    }
    int xpos = static_cast<int>(lua_tointeger(L, 1));

    if (!lua_isnumber(L, 2)) {
        lua_pushstring(L, "Error: Second argument must be an integer.");
        return 1;
    }
    int ypos = static_cast<int>(lua_tointeger(L, 2));

    if (!lua_isstring(L, 3)) {
        lua_pushstring(L, "Error: Third argument must be a string.");
        return 1;
    }
    const char* texname = lua_tostring(L, 3);

    map.tiles.emplace_back(MapTile(xpos,ypos,get_texture(texname)));

    return 0;
}

int luar_set_player_position(lua_State* L) {
    //at least 2 args
    if (lua_gettop(L) >= 2) {
        if (lua_isnumber(L, -2) && lua_isnumber(L, -1)) {
            float xpos = lua_tonumber(L, -2);  //first argument
            float ypos = lua_tonumber(L, -1);  //second argument 

            playerpos = GameVector(xpos,ypos);

        } else {
            lua_pushstring(L, "LUA ERROR : player.setpos() expects two numbers");
            lua_error(L);
        }
    } else {
        lua_pushstring(L, "LUA ERROR : player.setpos() expects two arguments");
        lua_error(L);
    }
    
    return 0;  // No return value
}

int luar_get_dt(lua_State* L){
    lua_pushnumber(L, dt/2000);
    return 1;
}

int luar_play_sound(lua_State* L){
    if (!lua_isstring(L, 1)) {
        lua_pushstring(L, "Error: Argument must be a string.");
        return 1;
    }
    const char* sfxpath = lua_tostring(L, 1);
    // play_sound(get_relative_path(sfxpath));
    (void)std::async(std::launch::async, play_sound, get_relative_path(sfxpath));

    return 0;
}

void lua_initregisters(){
    lua_register(L, "set_player_position", luar_set_player_position); // makes "set_speed" (lua) run the function set_speed (c++)
    lua_register(L, "get_dt", luar_get_dt); // gets delta time
    lua_register(L, "add_tile", luar_add_tile); // adds tile on map
    lua_register(L, "play_sound", luar_play_sound); // adds tile on map
}
