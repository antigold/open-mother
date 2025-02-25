#include "lua.h"

// lua state (global)
lua_State* L = nullptr;

//from chatgpt to debug
void dumpLuaStack(lua_State *L) {
    int stackSize = lua_gettop(L);
    std::cout << "Lua stack size: " << stackSize << std::endl;
    for (int i = 1; i <= stackSize; ++i) {
        int t = lua_type(L, i);
        switch (t) {
            case LUA_TSTRING:
                std::cout << "  " << i << ": string - " << lua_tostring(L, i) << std::endl;
                break;
            case LUA_TBOOLEAN:
                std::cout << "  " << i << ": boolean - " << (lua_toboolean(L, i) ? "true" : "false") << std::endl;
                break;
            case LUA_TNUMBER:
                std::cout << "  " << i << ": number - " << lua_tonumber(L, i) << std::endl;
                break;
            case LUA_TFUNCTION:
                std::cout << "  " << i << ": function" << std::endl;
                break;
            case LUA_TTABLE:
                std::cout << "  " << i << ": table" << std::endl;
                break;
            default:
                std::cout << "  " << i << ": " << lua_typename(L, t) << std::endl;
                break;
        }
    }
}

bool init_lua() {
    //lua state
    L = luaL_newstate();
    luaL_openlibs(L);

    // Load and run the Lua script
    if (luaL_dofile(L, get_relative_path("lua/test.lua")) != LUA_OK) {
        put(ERROR_CODE, "Error loading Lua script");
        put(FOLLOW_CODE, lua_tostring(L, -1));
        lua_close(L);
        return false;
    }

    lua_initregisters();
    lua_callfunction(L, "main"); // calls main and im not even gonna check for error cuz it wont crash anyway
    
    return true;
}

void exit_lua(){
    lua_close(L);
}

// TODO try removing all "put"
// TODO check something up with the changed code like the header name